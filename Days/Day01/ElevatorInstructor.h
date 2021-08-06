//
// Created by Stengel on 7/27/2021.
//

#pragma once

#include <memory>
#include <utility>
#include <string>
#include <vector>

class Elevator;

class ElevatorInstructor
{
 public:
	explicit ElevatorInstructor(std::shared_ptr<Elevator> t_elevator) : m_elevator(std::move(t_elevator))
	{
	};

	virtual void invoke(char t_instruction);

	virtual void invoke(const std::vector<char>& t_instructions);

	virtual ~ElevatorInstructor() = default;

 protected:
	std::shared_ptr<Elevator> m_elevator;
};


