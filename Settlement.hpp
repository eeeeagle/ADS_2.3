#pragma once
#ifndef SETTLEMENT
#define SETTLEMENT

#include <iostream>
#include <iomanip>
#include "Vertex.hpp"


class Settlement : public Vertex
{
	std::string name;
	size_t		population;

public:
	Settlement(const std::string& name, const size_t& population = 0)
		: name(name), population(population)
	{}

	std::string get_name() const
	{
		return name;
	}

	size_t get_population() const
	{
		return population;
	}

	bool operator ==(const Settlement& other) const
	{
		return (name == other.name && population == other.population);
	}

	bool operator !=(const Settlement& other) const
	{
		return !(*this == other);
	}

	friend std::ostream& operator <<(std::ostream& os, const Settlement& obj);
};

std::ostream& operator <<(std::ostream& os, const Settlement& obj)
{
	/*
	os << std::setw(5) << obj.id;
	os << std::setw(20) << obj.name;
	os << std::setw(15) << obj.population;
	*/

	os << '[' << obj.id << "] " << obj.name << std::endl;
	os << "Population: " << obj.population << std::endl;
	return os;
}
#endif
