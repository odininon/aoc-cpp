#include <vector>
#include <string>
#include <fstream>
#include "Days/Day01/Day01.h"
#include "Days/Day02/Day02.h"
#include "Days/Day03/Day03.h"
#include "Days/Day05/Day05.h"
#include "Days/Day06/Day06.h"
#include "Days/Day07/Day07.h"

#ifdef RUN_BRUTE_FORCE_DAYS
#include "Days/Day04/Day04.h"
#endif

std::vector<std::string> ReadDayInput(int day)
{
	std::vector<std::string> lines;

	std::ifstream file("./inputs/day" + std::to_string(day));
	std::string str;

	while (std::getline(file, str))
	{
		lines.push_back(str);
	}

	return lines;
}

int main()
{
	Day01 day01{ ReadDayInput(1) };
	day01.Part1();
	day01.Part2();

	Day02 day02{ ReadDayInput(2) };
	day02.Part1();
	day02.Part2();

	Day03 day03(ReadDayInput(3));
	day03.Part1();
	day03.Part2();

#ifdef RUN_BRUTE_FORCE_DAYS
	//	Day04 day04({});
	//	day04.Part1();
	//	day04.Part2();
#endif

	Day05 day05(ReadDayInput(5));
	day05.Part1();
	day05.Part2();

	Day06 day06(ReadDayInput(6));
	day06.Part1();
	day06.Part2();

	Day07 day07(ReadDayInput(7));
	day07.Part1();
	day07.Part2();

	return 0;
}

