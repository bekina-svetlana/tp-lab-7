// Copyright 2021 Bekina Svetlana
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "ocean.h"

Ocean::Ocean(double percent_prey, double percent_predator,
	double percent_stone) {
	cells = new Cell* [N];
	for (int i = 0; i < N; i++) {
		cells[i] = new Cell [M];
		for (int j = 0; j < M; j++) {
			cells[i][j].init({ i, j }, this);
		}
	}
	createPrey(percent_prey);
	createPredator(percent_predator);
	createStone(percent_stone);
}
void Ocean::createPrey(double percent_prey) {
	int prey = static_cast<int>(percent_prey * N * M);
	srand(time(0));
	for (int i = 0; i < prey; i++) {
		bool flag = true;
		while (flag) {
			int x = rand() % N;
			int y = rand() % M;
			if (cells[x][y].obj == nullptr) {
				Prey* new_prey = new Prey(10 + rand() % 100, 10 + rand() % 100 , &cells[x][y]);
				cells[x][y].obj = new_prey;
				stuff.push_back(new_prey);
				flag = false;
			}
		}
	}
}

void Ocean::createPredator(double percent_predator) {
	int predator = static_cast<int>(percent_predator * N * M);
	srand(time(0));
	for (int i = 0; i < predator; i++) {
		bool flag = true;
		while (flag) {
			int x = rand() % N;
			int y = rand() % M;
			if (cells[x][y].obj == nullptr) {
				Predator* new_predator = new Predator(1 + rand() % 11, 10 + rand() % 100,
					10 + rand() % 100, &cells[x][y]);
				new_predator->setObjType(ObjType::PREDATOR);
				cells[x][y].obj = new_predator;
				stuff.push_back(new_predator);
				flag = false;
			}
		}
	}
}
void Ocean::createStone(double percent_stone) {
	int stone = static_cast<int>(percent_stone * N * M);
	std::cout << stone << std::endl;
	srand(time(0));
	for (int i = 0; i < stone; i++) {
		bool flag = true;
		while (flag) {
			int x = rand() % N;
			int y = rand() % M;
			if (cells[x][y].obj == nullptr) {
				Stone* new_stone = new Stone(&cells[x][y]);
				cells[x][y].obj = new_stone;
				stuff.push_back(new_stone);
				flag = false;
			}
		}
	}
}
Cell* Ocean::findCell(Pair crd) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cells[i][j].crd.x == crd.x and cells[i][j].crd.y == crd.y) {
				return &cells[i][j];
			}
		}
	}
}

void Ocean::print() const {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cells[i][j].getObject() == nullptr)
				std::cout << ".";
			else if (cells[i][j].getObject()->getObjType() == ObjType::STONE)
				std::cout << STONE_N;
			else if (cells[i][j].getObject()->getObjType() == ObjType::PREY)
				std::cout << PREY_N;
			else if (cells[i][j].getObject()->getObjType() == ObjType::PREDATOR)
				std::cout << PREDATOR_N;
		}
		std::cout << "\n";
	}
}
void Ocean::run() {
	
	while (true) {
		int count = 1;
		for (Object* object : stuff) {
			if (object == nullptr)
				continue;
			count++;
			object->live();
		}
		print();
		system("pause");
	}
}

void Ocean::addObjects(Object* object) {
	stuff.push_back(object);
}