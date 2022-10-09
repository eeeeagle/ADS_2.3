#pragma once
#ifndef ROAD
#define ROAD

#include <iostream>
#include "Edge.hpp"

class Road : public Edge
{
	enum Surface_Type
	{
		ASPHALT,
		CONCRETE,
		DIRT,
		SAND
	};

	size_t	surface_type;
	bool	toll_road;
	double	distance;

public:
	Road(const double& distance, const size_t& surface_type = 0, const bool toll_road = false)
		: surface_type(surface_type), toll_road(toll_road), distance(distance)
	{}

	double get_distence() const
	{
		return distance;
	}
	
	std::string get_surface_type() const
	{
		switch (surface_type)
		{
		case Surface_Type::ASPHALT:
			return "ASPHALT";
		case Surface_Type::CONCRETE:
			return "CONCRETE";
		case Surface_Type::DIRT:
			return "DIRT";
		case Surface_Type::SAND:
			return "SAND";
		}
		return "UNKNOWN TYPE";
	}
	
	bool is_toll() const
	{
		return toll_road;
	}

	std::ostream& operator <<(std::ostream& os) const
	{
		os << '[' << id << "] " << get_surface_type();
		if (toll_road)
		{
			os << ", Toll road";
		}
		os << std::endl;
		os << "Distance: " << distance << std::endl;
		return os;
	}
};
#endif