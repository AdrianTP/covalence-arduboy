#include "Arduino.h"
#include "../headers/config.h"
#include "../headers/atom.h"
#include "../headers/generator.h"

Generator::Generator() {

	for (int i = 0; i < QUEUE_LENGTH; i ++) {
		this->queue[i] = -1;
	}
};

Generator::~Generator() {};

void Generator::addAtomIdToEndOfQueue(int atomId) {
	this->queue[numAtoms] = atomId;

	this->numAtoms ++;
};

int Generator::getRandomAtomValence() {
	int atomValence = random(1, 5);

	return atomValence;
}

int Generator::getNumAtoms() {
	return this->numAtoms;
};

int Generator::pullAtomIdOffFrontOfQueue() {
	if (this->numAtoms == 0) {
		return -1;
	} else {
		int topOfQueueId = this->queue[0];

		this->numAtoms --;

		this->scoot();

		return topOfQueueId;
	}
};

int Generator::swapAtomIdOnFrontOfQueue(int atomId) {
	int topOfQueueId = this->queue[0];

	this->queue[0] = atomId;

	return topOfQueueId;
};

void Generator::scoot() {
	for (int i = 0; i < this->numAtoms; i ++) {
		if (i == this->numAtoms) {
			this->queue[i] = 0;
		} else {
			this->queue[i] = queue[i + 1];
		}
	}
};
