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



	return 0;
}