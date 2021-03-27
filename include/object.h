// Copyright 2021 Bekina Svetlana
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, PREY, PREDATOR };

class Cell;

class Object {
private:
	ObjType type;
protected:
	Cell * cell;
public:
	Object(ObjType, Cell* = nullptr);
	virtual ~Object();
	virtual void live() = 0; // жизнь объекта
	void setCell(Cell*);
	void setObjType(ObjType);
	ObjType getObjType() const;
};
#endif  // INCLUDE_OBJECT_H_
