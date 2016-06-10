#ifndef MENUS_H
#define MENUS_H

// State machine values
const int STATE_INIT = 2;           // Which of the below states should the game start in?
const int STATE_MENU_CREDITS = 1;   // Credits screen
const int STATE_MENU_MAIN = 2;      // Main Menu screen     --  menu: Start, High Scores, Credits   --
const int STATE_MENU_OVER = 3;      // Game Over screen     --  menu: Main Menu                     --
const int STATE_MENU_PAUSE = 4;     // Pause screen         --  menu: Resume, Quit                  --
const int STATE_MENU_SCORES = 5;    // High scores screen   --  menu: Back                          --
const int STATE_PLAY = 6;           // Gameplay screen      --  menu: (none)                        --  buttons:

const int MENU_LIST_LENGTH = 3;

// Struct for menu items
typedef struct MenuItem {
	char label;
	int state;
};

// Struct for menu screens
typedef struct Menu {
	char title;
	MenuItem list[MENU_LIST_LENGTH];
};

// Credits screen
const Menu MENU_CREDITS = {
	'Credits',
	{
		{ 'Main Menu', STATE_MENU_MAIN },
		{ ' ', -1 },
		{ ' ', -1 }
	}
};

// Main Menu screen
const Menu MENU_MAIN = {
	'Covalence',
	{
		{ 'Play', STATE_PLAY },
		{ 'High Scores', STATE_MENU_SCORES },
		{ 'Credits', STATE_MENU_CREDITS }
	}
};

// Game Over screen
const Menu MENU_OVER = {
	'Game Over',
	{
		{ 'Main Menu', STATE_MENU_MAIN },
		{ ' ', -1 },
		{ ' ', -1 }
	}
};

// Pause screen
const Menu MENU_PAUSE = {
	'Paused',
	{
		{ 'Resume', STATE_PLAY },
		{ 'Quit', STATE_MENU_OVER },
		{ ' ', -1 }
	}
};

// High Scores screen
const Menu MENU_SCORES = {
	'High Scores',
	{
		{ 'Main Menu', STATE_MENU_MAIN },
		{ ' ', -1 },
		{ ' ', -1 }
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
