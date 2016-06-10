#ifndef GAME_H
#define GAME_H

class Arduboy;
class Board;
class Generator;
class Manifest;

typedef struct Menu;

class Game {
	private:
		// Class Instances
		Arduboy* arduboy;
		Board* board;
		Generator* generator;
		Manifest* manifest;

		// Vars
		int cursor_x;
		int cursor_y;
		int currentState; // STATE_INIT, STATE_MENU, STATE_OVER, STATE_PAUSE, STATE_PLAY
		int lastAtomMillis;
		int menuLength;
		int menu_y;
		int millisLimit;
		int targetState;

	public:
		// Constructor
		Game();

		// Destructor
		virtual ~Game();

		//
		void draw();

		//
		void drawMenu(Menu targetMenu);

		//
		void drawMenuItem(char label, int line);

		//
		void drawMenuTitle(char title);

		//
		void drawText(int x, int y, char text);

		// Processes the button-press data provided by the internal Arduboy instance
		void handleInput();

		// Processes button-presses for menu screens
		void handleMenuInput();

		// Processes button-presses for the Gameplay screen
		void handlePlayInput();

		//
		void handleStateCredits();

		//
		void handleStateMain();

		//
		void handleStateOver();

		//
		void handleStatePause();

		//
		void handleStateScores();

		//
		void handleStatePlay();

		//
		void handleState();

		// Initialises this instance of the Game class
		void setup();

		//
		void start();

		// Actions which need to be called on every iteration of the game loop
		void tick();
};

#endif
