//
// Created by Stengel on 8/4/2021.
//

#pragma once

#include <utility>
#include "../Day.h"

class Day04 : public Day<std::string>
{
 public:
	explicit Day04(std::vector<std::string> input) : Day<std::string>(4, std::move(input))
	{
	}

	void Part1() override;

	void Part2() override;
};


