//
// Created by Stengel on 7/28/2021.
//

#pragma once

#include <utility>
#include <vector>
#include <string>

template<typename T>
class Day
{
 public:
	explicit Day(int day, std::vector<T> t_input) : input(std::move(t_input))
	{
		printf("Day %i\n", day);
	}

	virtual void Part1() = 0;

	virtual void Part2() = 0;

	virtual ~Day() = default;

 protected:
	std::vector<T> input;
};


