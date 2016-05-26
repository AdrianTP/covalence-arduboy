#ifndef GAME_H
#define GAME_H

class Game {
	Board board;
	Generator generator;
	Manifest manifest;

	public:
	Game();
	void setup();
	void tick();
};

#endif
