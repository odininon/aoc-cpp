//
// Created by Stengel on 8/5/2021.
//

#pragma once

#include <utility>

#include "../Day.h"

class Day05 : public Day<std::string>
{
 public:
	explicit Day05(std::vector<std::string> t_input) : Day<std::string>(5, std::move(t_input))
	{
	};

	void Part1() override;

	void Part2() override;
};


