#ifndef MANIFEST_H
#define MANIFEST_H

class Manifest {
	int maxLength;
	int currentLength = 0;
	Atom* manifest[];
	void reindexAtomsFromIndex(int index);

	public:
	Manifest();
	int getAtomIndexById(int id);
	Atom* getAtomPointerAtIndex(int index);
	void addAtomPointer(Atom* atom);
	int scoreAtomPointerAtIndex(int index);
	Atom* deleteAtomPointerAtIndex(int index);
};

#endif
