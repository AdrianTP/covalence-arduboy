#include "../headers/config.h"
#include "../headers/manifest.h"

Manifest::Manifest() {
	maxLength = BOARD_HEIGHT * BOARD_WIDTH * QUEUE_LENGTH;
}

void Manifest::reindexAtomsFromIndex(int index) {
	for (var i = index; i < currentLength; i ++) {
		if (i = currentLength - 1) {
			manifest[i] = NULL;
		} else {
			manifest[i] = manifest[i + 1];
		}
	}
}

int Manifest::getAtomIndexById(int id) {
	for (int i = 0; i < currentLength; i ++) {
		Atom* atom = manifest[i];
		int targetId = atom->getId();

		if (targetId == id) {
			return i;
		}
	}

	return -1; // Not found
}

Atom* Manifest::getAtomPointerAtIndex(int index) {
	return manifest[index];
}

void Manifest::addAtomPointer(Atom* atom) {
	// TODO: perhaps rather than appending to the array, seek first open slot so we can just directly delete/overwrite atoms
	for (int i = 0; i < currentLength; i ++) {\

	}
	manifest[currentLength] = atom;
	currentLength ++;
}

int Manifest::scoreAtomPointerAtIndex(int index) {
	Atom* atom = manifest[index];
	int points = atom->getPoints();

	return points;
}

Atom* Manifest::deleteAtomPointerAtIndex(int index) {
	// TODO:
	// Make new array
	// Move all elements before and after index into new array
	// Delete old array
	char *old = manifest[index];
	delete old;
	reindexAtomsFrom(index);
	currentLength --;

	return old;
}
