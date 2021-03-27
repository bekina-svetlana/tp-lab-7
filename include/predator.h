// Copyright 2021 Bekina Svetlana
#ifndef _PREDATOR_H_
#define _PREDATOR_H_

#include "prey.h"

class Cell;

class Predator : public Prey {
private:
	int satiety_level = 10;
public:
	Predator(int new_satiety_level, int new_period, int new_reproduction, Cell* new_cell) :
		Prey(new_period, new_reproduction, new_cell) {
		satiety_level = new_satiety_level;
	}
	void live() override;
	void move();
};
#endif  // INCLUDE_PREDATOR_H_
