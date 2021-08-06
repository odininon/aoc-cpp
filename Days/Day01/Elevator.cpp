//
// Created by Stengel on 7/27/2021.
//

#include "Elevator.h"

int Elevator::GetCurrentFloor() const
{
	return current_floor;
}

void Elevator::Up(int amount)
{
	current_floor += amount;
}

void Elevator::Down(int amount)
{
	Up(-amount);
}
