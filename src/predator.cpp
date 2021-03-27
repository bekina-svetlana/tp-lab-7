// Copyright 2021 Bekina Svetlana
#include "predator.h"
#include "cell.h"

void Predator::live() {
	
	move();
	if (getAge() == getPeriod()) {
		cell->killMe();
		cell->setObject(nullptr);
	}
	else if (satiety_level == 0) {
		cell->killMe();
		cell->setObject(nullptr);
	}
	else if (getAge() % getReproduction() == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				Cell* new_cell = cell->getOcean()->findCell({ i, j});
				if (new_cell->isEmpty()) {
					Predator* new_predator = new Predator(1 + rand() % 11, 10 + rand() % 100,
						10 + rand() % 100, new_cell);
					new_predator->setObjType(ObjType::PREDATOR);
					new_cell->setObject(new_predator);
					new_cell->getOcean()->addObjects(new_predator);
					return;
					
				}
			}
		}
	}
}
void Predator::move() {
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if ((i != 0 or j != 0) and cell->getX() + i > 0 and cell->getY() + j > 0 and cell->getX() + i < N and cell->getY() + j < M) {
				Cell* new_cell = cell->getOcean()->findCell({ cell->getX() + i, cell->getY() + j });
				if (new_cell->isEmpty()) {
					cell->setObject(nullptr);
					new_cell->setObject(this);
					setCell(new_cell);
				}
				else if (new_cell->getObject()->getObjType() == ObjType::PREY) {
					satiety_level++;
					cell->setObject(nullptr);
					new_cell->setObject(this);
					setCell(new_cell);
				}
			}
		}
	}
	satiety_level--;
	addAge();
}