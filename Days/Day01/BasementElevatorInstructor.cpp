//
// Created by Stengel on 7/28/2021.
//

#include "BasementElevatorInstructor.h"

class Elevator
{
 public:
	int GetCurrentFloor() const;
};

int BasementElevatorInstructor::GetBasementInstruction() const
{
	return current_instruction_index;
}

void BasementElevatorInstructor::invoke(const std::vector<char>& t_instructions)
{
	for (auto i = 0; i < t_instructions.size(); i++)
	{
		auto instruction = t_instructions[i];

		ElevatorInstructor::invoke(instruction);

		if (m_elevator->GetCurrentFloor() < 0)
		{
			current_instruction_index = i + 1;
			break;
		}
	}
}
