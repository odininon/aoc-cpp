//
// Created by Stengel on 8/5/2021.
//

#include "Day06.h"

#include <regex>
#include <string>

void Day06::SetLightState(int x, int y, LightState state)
{
	switch (state)
	{
	case On:
		grid[x][y] = true;
	case Off:
		grid[x][y] = false;
	case Toggle:
		grid[x][y] = !grid[x][y];
	}
}

void Day06::SetRangeState(int x1, int y1, int x2, int y2, LightState state)
{
	for (auto x = x1; x <= x2; ++x)
	{
		for (auto y = y1; y <= y2; ++y)
		{
			SetLightState(x, y, state);
		}
	}
}

int Day06::NumberOfLightsOn()
{
	int count = 0;

	for (auto& x : grid)
	{
		for (bool y : x)
		{
			if (y)
			{
				count += 1;
			}
		}
	}

	return count;
}

void Day06::RunInstruction(const std::string& state, int x1, int y1, int x2, int y2)
{
	LightState s;

	if (state == "turn on")
	{
		s = On;
	}

	if (state == "turn off")
	{
		s = Off;
	}

	if (state == "toggle")
	{
		s = Toggle;
	}

	SetRangeState(x1, y1, x2, y2, s);
}

void Day06::Part1()
{
	std::regex str_expr(R"((turn on|turn off|toggle)\s(\d*),(\d*)\sthrough\s(\d*),(\d*))");

	for (const auto& i: input)
	{
		std::smatch sm;
		if (std::regex_match(i, sm, str_expr))
		{
			RunInstruction(
				sm.str(1),
				std::stoi(sm.str(2)),
				std::stoi(sm.str(3)),
				std::stoi(sm.str(4)),
				std::stoi(sm.str(5))
			);
		}
	}
	auto count = NumberOfLightsOn();
	printf("%i\n", count);
}

void Day06::Part2()
{

}

