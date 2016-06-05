#ifndef GAME_H
#define GAME_H

class Board;
class Generator;
class Manifest;

class Game {
	private:
		Board* board;
		Generator* generator;
		Manifest* manifest;

	public:
		Game();
		virtual ~Game();
		void setup();
		void tick();
};

#endif
