#pragma once
#ifndef EDGE
#define EDGE

class Edge
{
private:
	static size_t count;
public:
	const size_t id;
	Edge()
		: id(count++)
	{}
};
size_t Edge::count = 0;

#endif