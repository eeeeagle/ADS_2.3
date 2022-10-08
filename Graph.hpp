#pragma once
#ifndef GRAPH
#define GRAPH
#include <vector>

template <typename T_Vertex, typename T_Edge, typename T_Equal = std::equal_to<T_Vertex>>
class Graph
{
    struct Graph_Edge
    {
        T_Vertex source;
        T_Vertex destination;
        T_Edge   edge;

        Graph_Edge(const T_Vertex& source, const T_Vertex& destination, const T_Edge& edge) 
            :source(source), destination(destination), edge(edge)
        {}
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
        if (!contains<T_Vertex>(vertex))
            vertex_list.push_back(vertex);
    }

    void erase_vert(const T_Vertex& vert)
    {
        T_Equal compare;
        for (auto iter : edge_list)
        {
            if (compare(edge_list[*iter].init, vert) || compare(edge_list[*iter].destination, vert))
            {
                edge_list.erase(iter);
                break;
            }
        }
        for (auto iter : vertex_list)
        {
            if (compare(vertex_list[*iter], vert))
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
};
#endif