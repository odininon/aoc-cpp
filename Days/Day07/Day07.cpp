//
// Created by Stengel on 8/6/2021.
//

#include "Day07.h"

#include <unordered_map>
#include <string>
#include <list>
#include <set>
#include <regex>

void WalkGraph(std::unordered_map<std::string, std::list<std::pair<std::string, int>>> adjacencyList,
	const std::string& key,
	std::set<std::string>* set)
{
	auto value = adjacencyList[key];
	for (const auto& t: adjacencyList[key])
	{
		(*set).insert(t.first);
		WalkGraph(adjacencyList, t.first, set);
	}
}

void Decode(const std::string& instruction,
	std::unordered_map<std::string, std::list<std::pair<std::string, int>>>* adjacencyList,
	void (* fn)(std::unordered_map<std::string, std::list<std::pair<std::string, int>>>*,
		const std::string&,
		const std::string&,
		int))
{
	std::regex str_expr(R"((.*bag)s contain (.*).)");
	std::regex str_bags(R"((\d*\s\w*\s\w*)\sbag)");

	std::smatch sm;
	std::vector<std::string> inner_bags;

	std::regex_match(instruction, sm, str_expr);

	std::string outer_bag = sm.str(1);
	std::string inner_bags_string = sm.str(2);

	std::smatch im;
	while (std::regex_search(inner_bags_string, im, str_bags))
	{
		auto t = im.str();
		inner_bags.emplace_back(t.c_str());
		inner_bags_string = im.suffix();
	}

	for (const auto& bag : inner_bags)
	{
		std::smatch ls;
		std::regex str_bob("(\\d+)\\s(.*)");

		std::regex_match(bag, ls, str_bob);

		auto bag_count = std::stoi(ls.str(1));

		fn(adjacencyList, outer_bag, ls.str(2), bag_count);
	}
}

void insertBagBackwards(std::unordered_map<std::string, std::list<std::pair<std::string, int>>>* adjacencyList,
	const std::string& outer_bag,
	const std::string& inner_bag,
	int bag_count)
{
	(*adjacencyList)[outer_bag].push_back(std::make_pair(inner_bag, bag_count));
}

void insertBag(std::unordered_map<std::string, std::list<std::pair<std::string, int>>>* adjacencyList,
	const std::string& outer_bag,
	const std::string& inner_bag,
	int bag_count)
{
	(*adjacencyList)[inner_bag].push_back(std::make_pair(outer_bag, bag_count));
}

void DecodeInstruction(const std::string& instruction,
	std::unordered_map<std::string, std::list<std::pair<std::string, int>>>* adjacencyList)
{
	Decode(instruction, adjacencyList, insertBag);
}

void DecodeInstructionBackwards(const std::string& instruction,
	std::unordered_map<std::string, std::list<std::pair<std::string, int>>>* adjacencyList)
{
	Decode(instruction, adjacencyList, insertBagBackwards);
}

void Day07::Part1()
{
	std::unordered_map<std::string, std::list<std::pair<std::string, int>>> adjacencyList;

	for (const auto& i: input)
	{
		DecodeInstruction(i, &adjacencyList);
	}

	std::set<std::string> bags;
	WalkGraph(adjacencyList, "shiny gold bag", &bags);

	printf("Count: %llu\n", bags.size());
}

int CountInsideBags(std::unordered_map<std::string, std::list<std::pair<std::string, int>>> adjacencyList,
	const std::string& key)
{
	auto includedBags = adjacencyList[key];

	int count = 0;

	if (includedBags.empty())
	{
		return count;
	}

	for (const auto& bag: includedBags)
	{
		count += bag.second + (bag.second * CountInsideBags(adjacencyList, bag.first));
	}

	return count;
}

void Day07::Part2()
{
	std::unordered_map<std::string, std::list<std::pair<std::string, int>>> adjacencyList;

	for (const auto& i: input)
	{
		DecodeInstructionBackwards(i, &adjacencyList);
	}

	auto count = CountInsideBags(adjacencyList, "shiny gold bag");

	printf("Count: %d\n", count);
}
