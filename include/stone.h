// Copyright 2021 Bekina Svetlana
#ifndef _STONE_H_
#define _STONE_H_

#include "object.h"

class Object;
class Cell;

class Stone : public Object{
public:
	explicit Stone(Cell* new_cell) : Object(ObjType::STONE, new_cell) {
		cell = new_cell;
	}
	void live() override;
};
#endif  // INCLUDE_STONE_H_
