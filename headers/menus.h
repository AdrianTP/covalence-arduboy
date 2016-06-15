#ifndef MENUS_H
#define MENUS_H

// State machine values
namespace ScreenState {
	enum ScreenState {
		CREDITS,    // Credits screen
		MAIN,       // Main Menu screen
		OVER,       // Game Over screen
		PAUSE,      // Pause screen
		PLAY,       // Gameplay screen
		SCORES      // High Scores screen
	};
};

const int STATE_INIT = 1;

const int MENU_LIST_LENGTH = 3;
const int MENU_STRING_LENGTH = 12;

// Struct for menu items
struct MenuItem {
	char label[MENU_STRING_LENGTH]; // The actual string
	int numChars; // The length of the visible portion of the string (for screen math)
	int state; // The target state
};

// Struct for menu titles
struct MenuTitle {
	char label[MENU_STRING_LENGTH]; // The actual string
	int numChars; // The length of the visible portion of the string (for screen math)
};

// Struct for menu screens
struct Menu {
	MenuTitle title; // The menu title text
	int numItems; // The number of menu items
	MenuItem list[MENU_LIST_LENGTH]; // The array of menu items to display
};

// Credits screen
const Menu MENU_CREDITS = {
	{ "Credits", 7 }, 1,
	{
		{ "Main Menu", 9, ScreenState::MAIN }
	}
};

// Main Menu screen
const Menu MENU_MAIN = {
	{ "Covalence", 9, }, 3,
	{
		{ "Play", 4, ScreenState::PLAY },
		{ "High Scores", 11, ScreenState::SCORES },
		{ "Credits", 7, ScreenState::CREDITS }
	}
};

// Game Over screen
const Menu MENU_OVER = {
	{ "Game Over", 9 }, 1,
	{
		{ "Main Menu", 9, ScreenState::MAIN }
	}
};

// Pause screen
const Menu MENU_PAUSE = {
	{ "Paused", 6 }, 2,
	{
		{ "Resume", 6, ScreenState::PLAY },
		{ "Quit", 4, ScreenState::OVER }
	}
};

// High Scores screen
const Menu MENU_SCORES = {
	{ "High Scores", 11 }, 1,
	{
		{ "Main Menu", 9, ScreenState::MAIN }
	}
};

#endif

//  States:
//      Credits:
//          Display:            List of names and mini-menu
//          Items:
//          -   Main Menu       Returns to the Main Menu screen
//          Buttons:
//          -   A_BUTTON        Selects highlighted menu item
//      Main Menu:
//          Display:            Game logo and menu
//          Items:
//          -   Play            Begins gameplay
//          -   High Scores     Navigates to the Scores screen
//          -   Credits         Navigates to the Credits screen
//          Buttons:
//          -   A_BUTTON        Selects highlighted menu item
//          -   DOWN_BUTTON     Selects the next menu item
//          -   UP_BUTTON       Selects the previous menu item
//      Game Over:
//          Display:            Previous gameplay score and mini-menu
//          Items:
//          -   Main Menu       Navigates to the Main Menu screen
//          Buttons:
//          -   A_BUTTON        Selects highlighted menu item
//      Pause:
//          Display:            'PAUSED' and mini-menu
//          Items:
//          -   Resume          Returns to Gameplay and resumes the game timer
//          -   Quit            Terminates the current gameplay session and navigates to the Game Over screen
//          Buttons:
//          -   A_BUTTON        Selects highlighted menu item
//          -   DOWN_BUTTON     Selects the next menu item
//          -   UP_BUTTON       Selects the previous menu item
//      Scores:
//          Display:            Top three scores and mini-menu
//          Items:
//          -   Main Menu       Returns to the Main Menu screen
//          Buttons:
//          -   A_BUTTON        Selects highlighted menu item
//      Gameplay:
//          Display:            Game board, queue, cursor, and current score
//          Buttons:
//          -   A_BUTTON        Selects highlighted menu item
//          -   B_BUTTON        Pauses the game timer and navigates to the Pause screen
//          -   DOWN_BUTTON     Moves the cursor down one cell on the game board
//          -   LEFT_BUTTON     Moves the cursor left one cell on the game board
//          -   RIGHT_BUTTON    Moves the cursor right one cell on the game board
//          -   UP_BUTTON       Moves the cursor up one cell on the game board
