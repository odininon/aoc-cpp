//
// Created by Stengel on 8/4/2021.
//

#pragma once

#include <utility>

#include "../Day.h"

class Cell
{
 public:
	int x = 0, y = 0;

	bool operator<(const Cell& o) const
	{
		return x < o.x || (x == o.x && y < o.y);
	}
};

using Direction = char;

class CellMover
{
 public:
	static Cell MoveDirection(Cell cell, const Direction& direction)
	{
		if (direction == '^')
		{
			return Cell{ cell.x, cell.y + 1 };
		}

		if (direction == 'v')
		{
			return Cell{ cell.x, cell.y - 1 };
		}

		if (direction == '<')
		{
			return Cell{ cell.x - 1, cell.y };
		}

		if (direction == '>')
		{
			return Cell{ cell.x + 1, cell.y };
		}

		return Cell{ cell.x, cell.y };
	}
};

class Day03 : public Day<char>
{
 public:
	explicit Day03(std::vector<char> t_input) : Day(3, std::move(t_input))
	{
	};

	explicit Day03(const std::vector<std::string>& strings) : Day03(MakeVector(strings))
	{
	};

	void Part1() override;

	void Part2() override;

 private:
	static std::vector<char> MakeVector(const std::vector<std::string>& it);
};


