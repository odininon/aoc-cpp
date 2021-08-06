//
// Created by Stengel on 8/5/2021.
//

#pragma once

#include <string>
#include "../Day.h"

enum LightState
{
	On,
	Off,
	Toggle
};

class Day06 : public Day<std::string>
{
 public:

	explicit Day06(std::vector<std::string> t_input) : Day(6, std::move(t_input))
	{
	};

	void Part1() override;

	void Part2() override;

 private:
	void SetLightState(int x, int y, LightState state);

	bool grid[1000][1000] = { false };

	void SetRangeState(int x1, int x2, int y1, int y2, LightState state);

	int NumberOfLightsOn();

	void RunInstruction(const std::string& state, int x1, int y1, int x2, int y2);
};


