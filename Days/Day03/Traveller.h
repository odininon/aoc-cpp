//
// Created by Stengel on 8/4/2021.
//

#pragma once

#include <memory>
#include "Day03.h"

class Traveller
{
 public:
	Cell MoveDirection(char i)
	{
		Cell newCell = CellMover::MoveDirection(location, i);
		location = newCell;
		return newCell;
	}

 private:
	Cell location = Cell{};
};


