//
// Created by Stengel on 7/27/2021.
//

#include "ElevatorInstructor.h"

class Elevator
{
 public:
	void Up(int amount);

	void Down(int amount);
};

void ElevatorInstructor::invoke(char t_instruction)
{
	if (t_instruction == '(')
	{
		m_elevator->Up(1);
	}

	if (t_instruction == ')')
	{
		m_elevator->Down(1);
	}
}

void ElevatorInstructor::invoke(const std::vector<char>& t_instructions)
{
	for (auto instruction: t_instructions)
	{
		invoke(instruction);
	}
}
