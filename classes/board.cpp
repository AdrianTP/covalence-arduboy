#include "../headers/config.h"
//#include "../headers/array2d.h"
#include "../headers/board.h"

Board::Board() {
//	delete [] board; // TODO: no shit it's fucking private I want to modify the private variable from within the motherfucking class you dick monkey
//	int board[BOARD_WIDTH][BOARD_HEIGHT];
//	Array2D board(BOARD_WIDTH, BOARD_HEIGHT);

	for (int x = 0; x < BOARD_WIDTH; x ++) {
		for (int y = 0; y < BOARD_HEIGHT; y ++) {
			board[x][y] = 0;
//			board.at(x, y) = 0;
		}
	}
}

int Board::readCellAtCoords(int x, int y) {
	return board[x][y];
}

void Board::emptyCellAtCoords(int x, int y) {
	board[x][y] = 0;
}

int Board::writeCellAtCoords(int x, int y, int atom) {
	int oldContents = board[x][y];

	board[x][y] = atom;

	return oldContents;
}
