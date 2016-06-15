#ifndef BOARD_H
#define BOARD_H

class Board {
	private:
		// Vars
		int board[BOARD_WIDTH][BOARD_HEIGHT];

	public:
		// Constructor
		Board();

		// Destructor
		virtual ~Board();

		// Sets the value of the specified cell to -1 to indicate emptiness
		void emptyCellAtCoords(int x, int y);

		// Gets the id of the Atom which is stored in the specified cell
		int getAtomIdAtCoords(int x, int y);

		//
		void init();

		// Sets the value of the specified cell to the specified Atom id
		void setAtomIdAtCoords(int x, int y, int atomId);
};

#endif
