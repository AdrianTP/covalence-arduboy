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
	if (canBond() == 1) {
		switch (dir) {
			case 12: // north
				bond_north = id;
				break;
			case 3: // east
				bond_east = id;
				break;
			case 6: // south
				bond_south = id;
				break;
			case 9: // west
				bond_west = id;
				break;
		}

		numBonds ++;
	}
};

int Atom::breakBond(int dir) {
	int id = 0;

	switch (dir) {
		case 12: // north
			id = bond_north;
			bond_north = 0;
			break;
		case 3: // east
			id = bond_east;
            bond_east = 0;
			break;
		case 6: // south
			id = bond_south;
            bond_south = 0;
			break;
		case 9: // west
			id = bond_west;
		    bond_west = 0;
			break;
	}

	if (id > 0 && numBonds > 0) {
		numBonds --;
	}

	return id;
};

int Atom::getId() {
	return id;
};

int Atom::getValence() {
	return valence;
};

int Atom::getPoints() {
	return numBonds * SCORE_MULTIPLIER;
};

int Atom::canBond() {
	if (numBonds < valence) {
		return 1;
	} else {
		return 0;
	}
};

void Atom::init() {
	active = false;
	bond_north = 0;
	bond_east = 0;
	bond_south = 0;
	bond_west = 0;
	id = 0;
	numBonds = 0;
	valence = 0;
};
