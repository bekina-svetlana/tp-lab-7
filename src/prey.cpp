// Copyright 2021 Bekina Svetlana
#include "prey.h"
#include "cell.h"

void Prey::live() {
	move();
	if (age == period_of_life) {
		cell->killMe();
	} else if (age % reproduction == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				Cell* new_cell = cell->getOcean()->findCell({ i, j });
				if (new_cell->isEmpty()) {
					Prey* new_prey = new Prey(10 + rand() % 100, 10 + rand() % 100, new_cell);
					new_cell->setObject(new_prey);
					new_cell->getOcean()->addObjects(new_prey);
					return;
				}
			}
		}
	}
}
void Prey::move() {
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if ((i != 0 or j != 0) and cell->getX() + i > 0 and cell->getY() + j > 0 and cell->getX() + i < N and cell->getY() + j < M) {
				Cell* new_cell = cell->getOcean()->findCell({ cell->getX() + i, cell->getY() + j });
				if (new_cell->isEmpty()) {
					cell->setObject(nullptr);
	
					new_cell->setObject(this);
					setCell(new_cell);
					
				}
			}
		}
	}
	addAge();
}

void Prey::addAge() {
	age++;
}
int Prey::getAge() const {
	return age;
}
int Prey::getReproduction() const {
	return reproduction;
}
int Prey::getPeriod() const {
	return period_of_life;
}