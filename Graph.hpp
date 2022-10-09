#pragma once
#ifndef GRAPH
#define GRAPH

#include <vector>
#include <set>
#include <iostream>
#include <iomanip>

template <typename T_Vertex, typename T_Edge, typename T_Equal = std::equal_to<T_Vertex>>
class Graph
{
    class Graph_Edge
    {
        T_Vertex source;
        T_Vertex destination;
        T_Edge   edge;

    public:
        Graph_Edge(const T_Vertex& source, const T_Vertex& destination, const T_Edge& edge) 
            :source(source), destination(destination), edge(edge)
        {}

        std::ostream& operator <<(std::ostream& os) const
        {
            //
            return os;
        }

        friend class Graph;
    };
    
    std::vector<T_Vertex>     vertex_list;
	std::vector<Graph_Edge>   edge_list;

public:
    bool contains(const T_Vertex& vertex) const
    {
        T_Equal compare;
        for (auto iter : vertex_list)
        {
            if (compare(iter, vertex))
                return true;
        }
        return false;
    }

    void add_vertex(const T_Vertex& vertex)
    {
        if (!contains(vertex))
            vertex_list.push_back(vertex);
    }

    void delete_vertex(const T_Vertex& vertex)
    {
        T_Equal compare;
        for (auto iter : edge_list)
        {
            if (compare(edge_list[*iter].init, vertex) || compare(edge_list[*iter].destination, vertex))
            {
                edge_list.erase(iter);
                break;
            }
        }
        for (auto iter : vertex_list)
        {
            if (compare(vertex_list[*iter], vertex))
            {
                vertex_list.erase(iter);
                break;
            }
        }
    }

    void add_edge(const T_Vertex& source, const T_Vertex& destination, const T_Edge& edge)
    {
        edge_list.push_back(Graph_Edge(source, destination, edge));
    }

    void add_edge(const size_t source, const size_t destination, const T_Edge& edge)
    {
        if (source < vertex_list.size() && destination < vertex_list.size())
        {
            edge_list.push_back(Graph_Edge(vertex_list[source], vertex_list[destination], edge));
        }        
    }

    void delete_edge(const T_Vertex& source, const T_Vertex& destination)
    {
        T_Equal compare;
        for (auto iter : edge_list)
        {
            if (compare(edge_list[*iter].init, source) && compare(edge_list[*iter].destination, destination)) 
            {
                edge_list.erase(iter);
                break;
            }
        }
    }

    std::vector<T_Vertex> bfs(const T_Vertex& vertex)
    {
        std::vector<T_Vertex>    bfs_vertex_list;
        std::vector<size_t>      visited;
        std::vector<T_Vertex>    queue;

        visited.push_back(vertex.id);
        queue.push_back(vertex);
        bfs_vertex_list.push_back(queue.front());

        while (!queue.empty())
        {
            for (auto iter_vertex : vertex_list)
            {
                for (auto iter_edge : edge_list)
                {
                    auto find_source_id         = std::find(visited.begin(), visited.end(), iter_edge.source.id);
                    auto find_destination_id    = std::find(visited.begin(), visited.end(), iter_edge.destination.id);

                    if ((iter_edge).source.id == iter_vertex.id && queue.front().id == iter_vertex.id
                        && ((find_source_id != visited.end() && find_destination_id == visited.end())
                            || (find_source_id == visited.end() && find_destination_id == visited.end())))
                    {
                        visited.push_back(iter_edge.destination.id);
                        queue.push_back(iter_edge.destination);
                        bfs_vertex_list.push_back(iter_edge.destination);
                    }
                }
            }
            if (!queue.empty()) 
                queue.erase(queue.begin());
            else 
                break;
        }
        return bfs_vertex_list;
    }

    std::vector<T_Vertex> bfs(const size_t& id)
    {
        if (id >= vertex_list.size())
        {
            throw -1;
        }
        const T_Vertex& ref = vertex_list[id];
        return bfs(ref);
    }

    void print() const
    {
        /*
        * const std::vector<T_Vertex>& vec
        * std::cout << std::setw(5)   << "ID";
        * std::cout << std::setw(20)  << "NAME";
        * std::cout << std::setw(15)  << "POPULATION" << std::endl << std::endl;
        */

        for (auto iter : vertex_list)
        {
            std::cout << iter << std::endl;
        }
    }
};
#endif