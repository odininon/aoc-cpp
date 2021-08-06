//
// Created by Stengel on 8/6/2021.
//

#pragma once

#include <string>
#include <utility>
#include "../Day.h"

class Day07 : public Day<std::string>
{
 public:
	explicit Day07(std::vector<std::string> t_input) : Day(7, std::move(t_input))
	{

	}

	void Part1() override;

	void Part2() override;
};


