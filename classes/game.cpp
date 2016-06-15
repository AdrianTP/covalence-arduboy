#include "Arduino.h"
#include "Arduboy.h"

#include "../headers/config.h"
#include "../headers/board.h"
#include "../headers/buttons.h"
#include "../headers/generator.h"
#include "../headers/manifest.h"
#include "../headers/menus.h"

#include "../headers/game.h"

Game::Game() {};

Game::~Game() {};

void Game::draw() {
	// TODO:
};

void Game::drawMenu(const Menu& targetMenu) {
	this->menuLength = targetMenu.numItems;
	this->drawMenuTitle(targetMenu.title);

	for (int line = 0; line < this->menuLength; line ++) {
		this->drawMenuItem(targetMenu.list[line], line);
	}
};

void Game::drawMenuItem(const MenuItem& item, int line) {
	int text_y = (line + 2);
	int screenWidthInChars = 128 / CHAR_WIDTH;
	// TODO: figure out centred text
//	int halfChars = item.numChars % 2 == 0 ? (item.numChars / 2) : ((item.numChars - 1) / 2);
	int text_x = 1;//(screenWidthInChars / 2) - halfChars;

	if (this->menu_y == line) {
		this->drawText(text_x - 1, text_y, ">");
	}

	this->drawText(text_x, text_y, item.label);

//	if (this->menu_y == line) {
//		this->drawText(text_x + item.numChars, text_y, "]");
//	}
};

void Game::drawMenuTitle(const MenuTitle& title) {
	int text_y = 0;
	int screenWidthInChars = 128 / CHAR_WIDTH;
	// TODO: Figure out centred text and brackets
//	int halfChars = title.numChars % 2 == 0 ? (title.numChars / 2) : ((title.numChars - 1) / 2);
	int text_x = 1;//(screenWidthInChars / 2) - halfChars;

	this->drawText(text_x, text_y, title.label);
};

void Game::drawText(int x, int y, const char text[]) {
	// we set our cursor x pixels to the right and y down from the top
	arduboy->setCursor(x * CHAR_WIDTH, y * CHAR_HEIGHT);

	// then we print to screen what is stored in our text variable we declared earlier
	arduboy->print(text);
};

void Game::handleInput() {
	this->buttonsCurrent = this->readButtons();

	if (this->currentState == ScreenState::PLAY) {
		this->handlePlayInput();
	} else {
		this->handleMenuInput();
	}

	this->buttonsPrevious = this->buttonsCurrent;
};

void Game::handleMenuInput() {
	// if the up button is pressed move tyhe cursor up
	if (this->buttonsCurrent.up && this->buttonsCurrent.up != this->buttonsPrevious.up && this->menu_y > 0) {
		this->menu_y --;
	}

	// if the down button is pressed move the cursor down
	if (this->buttonsCurrent.down && this->buttonsCurrent.down != this->buttonsPrevious.down && this->menu_y < this->menuLength - 1) {
		this->menu_y ++;
	}

	if (this->buttonsCurrent.a && this->buttonsCurrent.a != this->buttonsPrevious.a) {
		this->currentState = this->targetState;
		this->menu_y = 0;
	}
};

void Game::handlePlayInput() {
	// TODO: This might be too sensitive for a tick-based game. In fact, I am positive it will be.
	// TODO: We may wish to only move the cursor after button is released.
	// TODO: We may wish to enable wrapping at edges since we're relying on a d-pad rather than a mouse or touch input.
	
	// TODO:
	// arrow buttons change cursor location
	// if cursor empty
		// remove first atom from queue and place in cursor location
	// else
		// swap atoms

	if (this->buttonsCurrent.down && this->buttonsCurrent.down != this->buttonsPrevious.down && this->cursor_y < BOARD_HEIGHT) {
		this->cursor_y ++;
	}

	if (this->buttonsCurrent.left && this->buttonsCurrent.left != this->buttonsPrevious.left && this->cursor_x > 0) {
		this->cursor_x --;
	}

	if (this->buttonsCurrent.right && this->buttonsCurrent.right != this->buttonsPrevious.right && this->cursor_x < BOARD_WIDTH) {
		this->cursor_x ++;
	}

	if (this->buttonsCurrent.up && this->buttonsCurrent.up != this->buttonsPrevious.up && this->cursor_y > 0) {
		this->cursor_y --;
	}

	if (this->buttonsCurrent.a && this->buttonsCurrent.a != this->buttonsPrevious.a) {
//		this->doAtomThing(); // TODO: grab atom
	}

	if (this->buttonsCurrent.b) {
		this->currentState = ScreenState::PAUSE;
		// TODO: pause game timer or something?
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

//	if (this->lastAtomMillis + millis() > this->millisLimit) {
//		int generatedValence = this->generator->getRandomAtomValence();
//
//		int atomId = this->manifest->addAtom(generatedValence);
//
//		this->generator->addAtomIdToEndOfQueue(atomId);
//
//		lastAtomMillis = millis();
//	}
//
//	if (this->arduboy->pressed(A_BUTTON)) { // button pressed
//		int currentCellAtom = this->board->getAtomIdAtCoords(this->cursor_x, this->cursor_y);
//		int nextAtomId = -1;
//
//		if (currentCellAtom == -1) { // if no atom present at current coords
//			nextAtomId = this->generator->pullAtomIdOffFrontOfQueue(); // pull atom off queue and place at coords
//		} else { // if atom present at current coords
//			nextAtomId = this->generator->swapAtomIdOnFrontOfQueue(currentCellAtom); // swap atom on queue with atom at coords
//		}
//
//		this->board->setAtomIdAtCoords(this->cursor_x, this->cursor_y, nextAtomId);
//	}
};

void Game::handleState() {
	switch (this->currentState) {
		// If we are currently playing the game
		case ScreenState::PLAY:
			this->handleStatePlay();
			break;

		// If we are at the Pause screen
		case ScreenState::PAUSE:
			this->handleStatePause();
			break;

		// If we are at the Game Over screen
		case ScreenState::OVER:
			this->handleStateOver();
			break;

		// If we are at the Main Menu screen
		case ScreenState::MAIN:
			this->handleStateMain();
			break;

		// If we are at the Credits screen
		case ScreenState::CREDITS:
			this->handleStateCredits();
			break;

		// If we are at the High Scores screen
		case ScreenState::SCORES:
			this->handleStateScores();
			break;
	}
};

ButtonState Game::readButtons() {
	ButtonState current = {
		this->arduboy->pressed(A_BUTTON),
		this->arduboy->pressed(B_BUTTON),
		this->arduboy->pressed(DOWN_BUTTON),
		this->arduboy->pressed(LEFT_BUTTON),
		this->arduboy->pressed(RIGHT_BUTTON),
		this->arduboy->pressed(UP_BUTTON)
	};

	return current;
};

void Game::serialDebug() {
	if (!SERIAL_DEBUG) {
		return;
	}

	if (this->arduboy->pressed(RIGHT_BUTTON)) {
		Serial.println("RIGHT");
	}

	if (this->arduboy->pressed(LEFT_BUTTON)) {
		Serial.println("LEFT");
	}

	// if the up button or B button is pressed move tyhe cursor up
	if (this->arduboy->pressed(UP_BUTTON)) {
		Serial.println("UP");
	}

	// if the down button or A button is pressed move the cursor down
	if (this->arduboy->pressed(DOWN_BUTTON) && this->cursor_y < BOARD_HEIGHT) {
		Serial.println("DOWN");
	}

	if (this->arduboy->pressed(A_BUTTON)) {
		Serial.println("A");
	}

//	if (this->arduboy->pressed(B_BUTTON)) {
//		Serial.println("B");
//	}

	if (millis() - this->lastDebugMillis > SERIAL_DEBUG_INTERVAL) {
		Serial.print(       "=============== ");    Serial.print(millis());             Serial.println();
		Serial.print(       "cursor_x:       ");    Serial.print(this->cursor_x);       Serial.println();
		Serial.print(       "cursor_y:       ");    Serial.print(this->cursor_y);       Serial.println();
		Serial.print(       "currenState:    ");    Serial.print(this->currentState);   Serial.println();
		Serial.print(       "lastAtomMillis: ");    Serial.print(this->lastAtomMillis); Serial.println();
		Serial.print(       "menuLength:     ");    Serial.print(this->menuLength);     Serial.println();
		Serial.print(       "menu_y:         ");    Serial.print(this->menu_y);         Serial.println();
		Serial.println();

		this->lastDebugMillis = millis();
	}
};

void Game::serialPrint(const char blah[]) {
	if (SERIAL_DEBUG) {
		Serial.print(blah);
	}
};

void Game::setup() {
	if (SERIAL_DEBUG) {
		Serial.begin(9600);
		this->lastDebugMillis = millis();
	}

	this->cursor_x = BOARD_WIDTH / 2;
	this->cursor_y = BOARD_HEIGHT / 2;
	this->currentState = STATE_INIT; // Initialise the game state machine
	this->lastAtomMillis = 0;
	this->menuLength = 0;
	this->menu_y = 0;
	this->millisLimit = GENERATOR_MILLIS_INIT; // testing

	this->arduboy = new Arduboy();
	this->board = new Board();
	this->generator = new Generator();
//	this->manifest = new Manifest(); // TODO: Figure out why this breaks the boot sequence when it is uncommented

	this->arduboy->begin();
	this->arduboy->setFrameRate(FRAMERATE);
};

void Game::start() {
	// TODO: Figure out how to call this only when transitioning from Main Menu screen to Gameplay screen
	if (RANDOM_SEED_DEBUG) {
		randomSeed(RANDOM_SEED_VALUE);
	} else {
		this->arduboy->initRandomSeed();
	}

	this->currentState = ScreenState::PLAY;
};

void Game::tick() {
	// Wait until the current frame is rendered before continuing
	if (!(this->arduboy->nextFrame())) {
		return;
	}

	// we clear our screen to black
	this->arduboy->clear();

	// Move along...
	this->handleState();

	this->handleInput();

	// then we finaly we tell the arduboy to display what we just wrote to the display.
	this->arduboy->display();

	this->serialDebug();
};
