// Copyright 2021 Bekina Svetlana
#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "cell.h"
#include "predator.h"
#include "stone.h"
#include <list>
#include <iostream>

class Ocean {
private:
	Cell** cells;
	std::list<Object*> stuff;
public:
	Ocean() {}
	explicit Ocean(double, double, double);
	~Ocean();
	void print() const;
	void addObjects(Object*);
	void run();
	Cell* findCell(Pair);
	void createPrey(double);
	void createPredator(double);
	void createStone(double);

};
#endif  // INCLUDE_OCEAN_H_
