#ifndef GAME_H
#define GAME_H

class Arduboy;
class Board;
class Generator;
class Manifest;

struct ButtonState;
struct Menu;

class Game {
	private:
		// Class Instances
		Arduboy* arduboy;
		Board* board;
		Generator* generator;
		Manifest* manifest;

		// Vars
		ButtonState buttonsCurrent;
		ButtonState buttonsPrevious;
		int cursor_x;
		int cursor_y;
		int currentState; // STATE_INIT, ScreenState
		unsigned long lastAtomMillis;
		unsigned long lastDebugMillis;
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
		void drawMenu(const Menu& targetMenu);

		//
		void drawMenuItem(const MenuItem& item, int line);

		//
		void drawMenuTitle(const MenuTitle& title);

		//
		void drawText(int x, int y, const char text[]);

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

		//
		ButtonState readButtons();

		//
		void serialDebug();

		//
		void serialPrint(const char blah[]);

		// Initialises this instance of the Game class
		void setup();

		//
		void start();

		// Actions which need to be called on every iteration of the game loop
		void tick();
};

#endif
