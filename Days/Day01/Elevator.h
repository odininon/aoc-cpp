//
// Created by Stengel on 7/27/2021.
//

#pragma once

class Elevator
{
 public:
	void Up(int amount);
	void Down(int amount);

	int GetCurrentFloor() const;

 private:
	int current_floor = 0;
};


