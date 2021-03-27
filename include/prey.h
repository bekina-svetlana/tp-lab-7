// Copyright 2021 Bekina Svetlana
#ifndef _PREY_H_
#define _PREY_H_

#include "object.h"

class Cell;

class Prey : public Object {
private:
	int period_of_life;
	int reproduction;
	int age = 1;
public:
	Prey(int new_period, int new_reproduction, Cell* new_cell) : Object(ObjType::PREY, new_cell) {
		period_of_life = new_period;
		reproduction = new_reproduction;
		cell = new_cell;
	}
	void live() override;
	void move();
	void addAge();
	int getAge() const;
	int getReproduction() const;
	int getPeriod() const;
};
#endif  // INCLUDE_PREY_H_
