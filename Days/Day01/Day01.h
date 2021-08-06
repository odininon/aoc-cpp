//
// Created by Stengel on 7/28/2021.
//

#pragma once

#include <utility>
#include <vector>
#include "../Day.h"

class Day01 : public Day<std::string>
{

 public:
	explicit Day01(const std::vector<std::string>& t_input) : Day(1, t_input)
	{
	}

	void Part1() override;

	void Part2() override;
};


