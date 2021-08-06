//
// Created by Stengel on 7/28/2021.
//

#include <string>
#include "Day01.h"
#include "Elevator.h"
#include "ElevatorInstructor.h"
#include "BasementElevatorInstructor.h"

std::vector<char> MakeInstructions(const std::vector<std::string>& string)
{
	std::vector<char> r;

	for (auto line: string)
	{
		std::vector<char> v(line.begin(), line.end());

		for (auto c: v)
		{
			r.push_back(c);
		}
	}

	return r;
}

void Day01::Part1()
{
	auto elevator = std::make_shared<Elevator>();
	auto instructor = std::make_shared<ElevatorInstructor>(elevator);

	auto instructions = MakeInstructions(input);

	instructor->invoke(instructions);
	auto current_floor = elevator->GetCurrentFloor();
	printf("Part 1: Ending floor: %i\n", current_floor);
}

void Day01::Part2()
{
	auto elevator = std::make_shared<Elevator>();
	auto instructor = std::make_shared<BasementElevatorInstructor>(elevator);

	auto instructions = MakeInstructions(input);

	instructor->invoke(instructions);
	auto first_basement_instruction = instructor->GetBasementInstruction();
	printf("Part 2: First basement instruction: %i\n", first_basement_instruction);
}



