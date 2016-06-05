#ifndef GENERATOR_H
#define GENERATOR_H

class Atom;

class Generator {
	private:
		Atom* queue[QUEUE_LENGTH];
//		int id;
//		int numAtoms;
//
//		int randomInt();
//		void scoot();

	public:
		Generator(int seed);
		virtual ~Generator();
//		void makeAtom();
//		Atom removeAtom();
};

#endif
