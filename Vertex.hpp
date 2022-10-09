#pragma once
#ifndef VERTEX
#define VERTEX

class Vertex
{
private:
	static size_t count;
public:
	const size_t id;
	Vertex() 
		: id(count++)
	{}
};
size_t Vertex::count = 0;

#endif