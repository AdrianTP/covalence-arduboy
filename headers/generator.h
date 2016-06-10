#ifndef GENERATOR_H
#define GENERATOR_H

class Generator {
	private:
		// Vars
		int queue[QUEUE_LENGTH];
		int numAtoms;

		// Methods
		// Rebuilds this->queue[] in the wake of this->pullAtomIdOffFrontOfQueue()
		void scoot();

	public:
		// Constructor
		Generator();//int seed);

		// Destructor
		virtual ~Generator();

		// Adds the specified Atom id to the end of the queue
		void addAtomIdToEndOfQueue(int atomId);

		// Generates a random integer representing the number of valence electrons for a new Atom
		int getRandomAtomValence();

		// Returns the current number of non-negative cells in this->queue[]
		int getNumAtoms();

		// Returns the id on the front of the queue and calls this->scoot() to reindex the array
		int pullAtomIdOffFrontOfQueue();

		// Places the specified id in this->queue[0] and returns the previous value of this->queue[0]
		int swapAtomIdOnFrontOfQueue(int atomId);
};

#endif
