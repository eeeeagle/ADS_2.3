#include "Graph.hpp"
#include "Road.hpp"
#include "Settlement.hpp"

int main()
{
	Graph<Settlement, Road> graph;
	
	graph.add_vertex(Settlement("Samara", 1136709));
	graph.add_vertex(Settlement("Tolyatti", 684709));
	graph.add_vertex(Settlement("Syzran", 162886));
	graph.add_vertex(Settlement("Novokuybyshevsk", 98373));
	graph.add_vertex(Settlement("Zhigulyovsk", 49921));
	graph.add_vertex(Settlement("Chapayevsk", 70096));

	graph.add_edge(0, 1, Road(70.0));
	graph.add_edge(0, 1, Road(50.0, 1, true));
	graph.add_edge(1, 4, Road(3.0));
	graph.add_edge(4, 2, Road(100.0));
	graph.add_edge(2, 5, Road(400.0));
	graph.add_edge(5, 3, Road(10.0, 2));
	graph.add_edge(5, 0, Road(40.0));
	graph.add_edge(5, 1, Road(150.0));
	graph.add_edge(3, 0, Road(20.0));
	graph.add_edge(3, 1, Road(130.0));

	graph.print();
	graph.bfs(0);

	return 0;
}