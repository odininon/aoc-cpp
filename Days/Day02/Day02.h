//
// Created by Stengel on 7/28/2021.
//

#pragma once

#include <utility>

#include "../Day.h"

class Day02 : public Day<std::string>
{
 public:
	explicit Day02(std::vector<std::string> t_input) : Day(2, std::move(t_input))
	{
	}

	void Part1() override;

	void Part2() override;
};


