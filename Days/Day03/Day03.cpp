#include "Day03.h"
#include "Traveller.h"

#include <set>
#include <algorithm>

void MoveCell(const std::vector<char>& input, const std::vector<Traveller*>& travellers)
{
	size_t index = 0;
	std::set<Cell> cells{};
	cells.insert(Cell{});

	for (char g : input)
	{
		auto traveller = travellers[index];
		Cell b = traveller->MoveDirection(g);
		cells.insert(b);
		index = (index + 1) % travellers.size();
	}

	printf("%llu\n", cells.size());
}

void Day03::Part1()
{
	auto traveller = new Traveller{};
	MoveCell(input, { traveller });
}

void Day03::Part2()
{
	auto traveller = new Traveller{};
	auto second_traveller = new Traveller{};
	MoveCell(input, { traveller, second_traveller });
}

std::vector<char> Day03::MakeVector(const std::vector<std::string>& basicString)
{
	std::vector<char> ret;

	for (auto it : basicString)
	{
		std::vector<char> v(it.begin(), it.end());

		for (auto c : v)
		{
			ret.push_back(c);
		}
	}
	return ret;
}


