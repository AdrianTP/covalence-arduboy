#ifndef BOARD_H
#define BOARD_H

class Board {
	private:
	int board[BOARD_WIDTH][BOARD_HEIGHT]; // TODO: multidimensional array BOARD_WIDTH by BOARD_HEIGHT
//	Array2D board;

	public:
	Board();
	int readCellAtCoords(int x, int y);
	void emptyCellAtCoords(int x, int y);
	int writeCellAtCoords(int x, int y, int atomIndexInManifest);
};

#endif
