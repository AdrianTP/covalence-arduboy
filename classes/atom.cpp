#include "../headers/config.h"
#include "../headers/atom.h"

Atom::Atom() {
	this->init();
};

Atom::~Atom() {};

void Atom::activate(int valence) {
	this->active = true;
	this->valence = valence;
};

void Atom::deactivate() {
	this->init();
};

void Atom::makeBond(int dir, int id) {
	if (this->canBond()) {
		switch (dir) {
			case 12: // north
				this->bond_north = id;
				break;
			case 3: // east
				this->bond_east = id;
				break;
			case 6: // south
				this->bond_south = id;
				break;
			case 9: // west
				this->bond_west = id;
				break;
		}

		numBonds ++;
	}
};

int Atom::breakBond(int dir) {
	int bondId = 0;

	switch (dir) {
		case 12: // north
			bondId = bond_north;
			this->bond_north = 0;
			break;
		case 3: // east
			bondId = bond_east;
			this->bond_east = 0;
			break;
		case 6: // south
			bondId = bond_south;
			this->bond_south = 0;
			break;
		case 9: // west
			bondId = bond_west;
			this->bond_west = 0;
			break;
	}

	if (bondId > 0 && this->numBonds > 0) {
		this->numBonds --;
	}

	return bondId;
};

int Atom::getValence() {
	return this->valence;
};

int Atom::getPoints() {
	return this->numBonds * SCORE_MULTIPLIER;
};

bool Atom::canBond() {
	return this->numBonds < this->valence;
};

void Atom::init() {
	this->active = false;
	this->bond_north = 0;
	this->bond_east = 0;
	this->bond_south = 0;
	this->bond_west = 0;
	this->numBonds = 0;
	this->valence = 0;
};

bool Atom::isActive() {
	return this->active;
};
