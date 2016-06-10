#include "Arduino.h"
#include "Arduboy.h"
#include "../headers/config.h"
#include "../headers/board.h"
#include "../headers/generator.h"
#include "../headers/manifest.h"
#include "../headers/menus.h"
#include "../headers/game.h"

Game::Game() {};

Game::~Game() {};

void Game::draw() {
	// TODO:
};

void Game::drawMenu(Menu targetMenu) {
	this->menuLength = 0;
	this->drawMenuTitle(targetMenu.title);

	for (int i = 0; i < MENU_LIST_LENGTH; i ++) {
		char label = targetMenu.list[i].label;
		int state = targetMenu.list[i].state;

		if (state > -1) { // -1 means invisible
			this->drawMenuItem(label, i);
			this->menuLength ++;
		}
	}
};

void Game::drawMenuItem(char label, int line) {
	int text_y = (line + 1) * CHAR_HEIGHT;
	int numChars = 0;
	int screenWidthInChars = 128 / CHAR_WIDTH;
	int text_x = (screenWidthInChars / 2) - (numChars / 2);

	if (this->menu_y == line) {
		this->drawText(text_x - 1, text_y, '[');
	}

	this->drawText(text_x, text_y, label);

	if (this->menu_y == line) {
		this->drawText(text_x + numChars + 1, text_y, ']');
	}
};

void Game::drawMenuTitle(char title) {
	int text_y = 0;
	int text_x = 0;
	int numChars = sizeof(title) - 1; // count number of chars in label
	int screenWidthInChars = 128 / CHAR_WIDTH;

	text_x = (screenWidthInChars / 2) - (numChars / 2);

	this->drawText(text_x, text_y, title);
};

void Game::drawText(int x, int y, char text) {
	// we set our cursor x pixels to the right and y down from the top
	arduboy->setCursor(x * CHAR_WIDTH, y * CHAR_HEIGHT);

	// then we print to screen what is stored in our text variable we declared earlier
	arduboy->print(text);
};

void Game::handleInput() {
	if (this->currentState == STATE_PLAY) {
		this->handlePlayInput();
	} else {
		this->handleMenuInput();
	}
};

void Game::handleMenuInput() {
	// if the up button is pressed move tyhe cursor up
	if (this->arduboy->pressed(UP_BUTTON) && this->menu_y > 0) {
		this->menu_y --;
	}

	// if the down button is pressed move the cursor down
	if (this->arduboy->pressed(DOWN_BUTTON) && this->menu_y < this->menuLength) {
		this->menu_y ++;
	}

	if (this->arduboy->pressed(A_BUTTON)) {
		this->currentState = this->targetState;
	}
};

void Game::handlePlayInput() {
	// TODO: This might be too sensitive for a tick-based game. In fact, I am positive it will be.
	// TODO: We may wish to only move the cursor after button is released.
	// TODO: We may wish to enable wrapping at edges since we're relying on a d-pad rather than a mouse or touch input.

	// if the right button is pressed move the cursor to the right
	if (this->arduboy->pressed(RIGHT_BUTTON)) {
		this->cursor_x ++;
	}

	// if the left button is pressed move the cursor to the left
	if (this->arduboy->pressed(LEFT_BUTTON) && this->cursor_x > 0) {
		this->cursor_x --;
	}

	// if the up button or B button is pressed move tyhe cursor up
	if (this->arduboy->pressed(UP_BUTTON) && this->cursor_y > 0) {
		this->cursor_y --;
	}

	// if the down button or A button is pressed move the cursor down
	if (this->arduboy->pressed(DOWN_BUTTON) && this->cursor_y < BOARD_HEIGHT) {
		this->cursor_y ++;
	}

	if (this->arduboy->pressed(A_BUTTON)) {
//		this->doAtomThing(); // TODO: grab atom
	}

	if (this->arduboy->pressed(B_BUTTON)) {
		this->currentState = STATE_MENU_PAUSE;
	}
};

void Game::handleStateCredits() {
	this->drawMenu(MENU_CREDITS);
	this->targetState = MENU_CREDITS.list[this->menu_y].state;
};

void Game::handleStateMain() {
	this->drawMenu(MENU_MAIN);
	this->targetState = MENU_MAIN.list[this->menu_y].state;
};

void Game::handleStateOver() {
	this->drawMenu(MENU_OVER);
	this->targetState = MENU_OVER.list[this->menu_y].state;
};

void Game::handleStatePause() {
	this->drawMenu(MENU_PAUSE);
	this->targetState = MENU_PAUSE.list[this->menu_y].state;
};

void Game::handleStateScores() {
	this->drawMenu(MENU_SCORES);
	this->targetState = MENU_SCORES.list[this->menu_y].state;
};

void Game::handleStatePlay() {
	// TODO: output graphics somehow
	// TODO: Finish game logic

	if (this->lastAtomMillis + millis() > this->millisLimit) {
		int generatedValence = this->generator->getRandomAtomValence();

		int atomId = this->manifest->addAtom(generatedValence);

		this->generator->addAtomIdToEndOfQueue(atomId);

		lastAtomMillis = millis();
	}

	if (this->arduboy->pressed(A_BUTTON)) { // button pressed
		int currentCellAtom = this->board->getAtomIdAtCoords(this->cursor_x, this->cursor_y);
		int nextAtomId = -1;

		if (currentCellAtom == -1) { // if no atom present at current coords
			nextAtomId = this->generator->pullAtomIdOffFrontOfQueue(); // pull atom off queue and place at coords
		} else { // if atom present at current coords
			nextAtomId = this->generator->swapAtomIdOnFrontOfQueue(currentCellAtom); // swap atom on queue with atom at coords
		}

		this->board->setAtomIdAtCoords(this->cursor_x, this->cursor_y, nextAtomId);
	}
};

void Game::handleState() {
	switch (this->currentState) {
		// If we are currently playing the game
		case STATE_PLAY:
			this->handleStatePlay();
			break;

		// If we are at the Pause screen
		case STATE_MENU_PAUSE:
			this->handleStatePause();
			break;

		// If we are at the Game Over screen
		case STATE_MENU_OVER:
			this->handleStateOver();
			break;

		// If we are at the Main Menu screen
		case STATE_MENU_MAIN:
			this->handleStateMain();
			break;

		// If we are at the Credits screen
		case STATE_MENU_CREDITS:
			this->handleStateCredits();
			break;

		// If we are at the High Scores screen
		case STATE_MENU_SCORES:
			this->handleStateScores();
			break;
	}
};

void Game::setup() {
	this->cursor_x = BOARD_WIDTH / 2;
	this->cursor_y = BOARD_HEIGHT / 2;
	this->currentState = STATE_INIT; // Initialise the game state machine
	this->lastAtomMillis = 0;
	this->menuLength = 0;
	this->menu_y = 0;
	this->millisLimit = GENERATOR_MILLIS_INIT;

	this->arduboy = new Arduboy();
	this->board = new Board();
	this->generator = new Generator();
	this->manifest = new Manifest();

	this->arduboy->setFrameRate(FRAMERATE);
};

void Game::start() {
	// TODO: Figure out how to call this only when transitioning from Main Menu screen to Gameplay screen
	if (RANDOM_SEED_DEBUG == 1) {
		randomSeed(RANDOM_SEED_VALUE);
	} else {
		this->arduboy->initRandomSeed();
	}

	this->currentState = STATE_PLAY;
};

void Game::tick() {
	// Wait until the current frame is rendered before continuing
	if (!(this->arduboy->nextFrame())) {
		return;
	}

	// we clear our screen to black
	arduboy->clear();

	// Move along...
	this->handleState();

	this->handleInput();

	// then we finaly we tell the arduboy to display what we just wrote to the display.
	arduboy->display();
};
