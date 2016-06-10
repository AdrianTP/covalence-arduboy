#ifndef ATOM_H
#define ATOM_H

class Atom {
	private:
		// Vars
		bool active;
		int bond_north;
		int bond_east;
		int bond_south;
		int bond_west;
		int numBonds;
		int valence;

		// Methods
		// Resets this Atom to baseline and marks it as inactive
		void init();

	public:
		// Constructor
		Atom();

		// Destructor
		virtual ~Atom();

		// Mark Atom as active and set valence electron value
		void activate(int valence);

		// Public alias for this->init()
		void deactivate();

		// If atom can bond, store the id of the Atom to which it is bonded
		void makeBond(int dir, int id);

		// Breaks the bond of the corresponding clock direction and returns the id of the Atom to which it was bonded
		int breakBond(int dir);

		// Does this Atom have available bonding slots?
		bool canBond();

		// Calculates how many points this Atom is worth when fully bonded
		int getPoints();

		// Returns the number of valence electrons this Atom has
		int getValence();

		// Is this Atom active?
		bool isActive();
};

#endif
