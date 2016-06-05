#ifndef ATOM_H
#define ATOM_H

class Atom {
	private:
		bool active;
		int bond_north;
		int bond_east;
		int bond_south;
		int bond_west;
		int id;
		int numBonds;
		int valence;

	public:
		Atom();
		virtual ~Atom();
		void activate(int valence);
		void deactivate();
		void makeBond(int dir, int id);
		int breakBond(int dir);
		int canBond();
		int getId();
		int getPoints();
		int getValence();
		void init();
};

#endif
