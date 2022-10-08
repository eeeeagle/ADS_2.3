#pragma once
#ifndef SETTLEMENT
#define SETTLEMENT
#include <iostream>

class Settlement
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
};
#endif
