#ifndef MANIFEST_H
#define MANIFEST_H

class Atom;

class Manifest {
	int maxLength;
	Atom* manifest[];

	public:
	Manifest();
	virtual ~Manifest();
//	int getAtomIndexById(int id);
//	Atom* getAtomPointerAtIndex(int index);
//	void addAtomPointer(Atom* atom);
//	int scoreAtomPointerAtIndex(int index);
	void init();
};

#endif
