// Copyright 2021 Bekina Svetlana
#include "cell.h"

void Cell::init(Pair new_crd, Ocean* new_ocean) {
	crd = new_crd;
	obj = nullptr;
	ocean = new_ocean;
}

Object* Cell::getObject() const {
	return obj;
}
void Cell::setObject(Object* new_obj) {
	obj = new_obj;
}

void Cell::killMe() {
	if (obj) {
		obj = nullptr;
	}
}
bool Cell::isEmpty() const {
	if (obj == nullptr) {
		return true;
	} else {
		return false;
	}
}

int Cell::getX() const {
	return crd.x;
}
int Cell::getY() const {
	return crd.y;
}
Ocean* Cell::getOcean() {
	return ocean;
}