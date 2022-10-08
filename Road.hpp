#pragma once
#ifndef ROAD
#define ROAD
#include <iostream>

class Road
{
	enum Surface_Type
	{
		ASPHALT,
		CONCRETE,
		DIRT,
		SAND
	};

	double	distance;
	size_t	surface_type;
	bool	toll_road;
public:
	Road(const double& distance, const size_t& type = 0, const bool toll_road = false)
		: surface_type(type), toll_road(toll_road)
	{
		if (distance <= 0.0)
			throw "Distance can't be below 0.";
		this->distance = distance;
	}

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
};
#endif