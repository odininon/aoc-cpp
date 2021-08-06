//
// Created by Stengel on 7/28/2021.
//

#include "Day02.h"
#include "Box.h"

#include <sstream>
#include <algorithm>

void Day02::Part1()
{
	int wrapping_paper_needed = 0;

	for (const auto& i: input)
	{
		auto box = Box::FromString(i);
		wrapping_paper_needed += box.WrappingPaperNeeded();
	}

	printf("Part 1: %i\n", wrapping_paper_needed);
}

void Day02::Part2()
{
	int ribbon_needed = 0;

	for (const auto& i: input)
	{
		auto box = Box::FromString(i);
		ribbon_needed += box.RibbonNeeded();
	}

	printf("Part 2: %i\n", ribbon_needed);
}
