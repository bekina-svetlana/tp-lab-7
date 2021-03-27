// Copyright 2021 Bekina Svetlana
#include "object.h"

Object::Object(ObjType new_type, Cell* new_cell) {
	cell = new_cell;
	type = new_type;
}
Object::~Object() {}

void Object::setCell(Cell* new_cell) {
	cell = new_cell;
}
ObjType Object::getObjType() const {
	return type;
}

void Object::setObjType(ObjType new_type) {
	type = new_type;
}