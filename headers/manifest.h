#ifndef MANIFEST_H
#define MANIFEST_H

class Atom;

class Manifest {
	private:
		// Vars

		// Stores the maximum length of the manifest
		int maxLength;

		// Stores all Atom instances
		Atom* manifest[];

		// Methods

		// Sets up this->manifest[] with a bunch of Atom instances
		void init();

	public:
		// Constructor
		Manifest();

		// Destructor
		virtual ~Manifest();

		// Finds the first inactive Atom in this->manifest[]
		int addAtom(int valence);

//		int getAtomIndexById(int id);
//		Atom* getAtomPointerAtIndex(int index);
//		void addAtomPointer(Atom* atom);
//		int scoreAtomPointerAtIndex(int index);
};

#endif
