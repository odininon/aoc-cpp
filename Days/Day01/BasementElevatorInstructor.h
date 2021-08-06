//
// Created by Stengel on 7/28/2021.
//

#pragma once

#include "ElevatorInstructor.h"

#include <utility>

class BasementElevatorInstructor : public ElevatorInstructor
{
 public:
	explicit BasementElevatorInstructor(std::shared_ptr<Elevator> t_elevator)
		: ElevatorInstructor(std::move(t_elevator))
	{
	}

	void invoke(const std::vector<char>& t_instructions) override;

	int GetBasementInstruction() const;

 private:
	int current_instruction_index = 0;
};


