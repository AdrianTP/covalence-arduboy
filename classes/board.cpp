#include "../headers/config.h"
#include "../headers/board.h"

Board::Board() {
	this->init();
};

Board::~Board() {};

void Board::emptyCellAtCoords(int x, int y) {
	this->setAtomIdAtCoords(x, y, -1);
};

int Board::getAtomIdAtCoords(int x, int y) {
	return board[x][y];
};

void Board::init() {
	for (int x = 0; x < BOARD_WIDTH; x ++) {
		for (int y = 0; y < BOARD_HEIGHT; y ++) {
			this->emptyCellAtCoords(x, y);
		}
	}
};

void Board::setAtomIdAtCoords(int x, int y, int atomId) {
	board[x][y] = atomId;
};
