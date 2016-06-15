#include "Arduino.h"
#include "Arduboy.h"

#include "atom_bitmaps.h"
#include "headers/config.h"
#include "headers/menus.h"

#include "headers/atom.h"
#include "headers/board.h"
#include "headers/buttons.h"
#include "headers/generator.h"
#include "headers/manifest.h"
#include "headers/game.h"

// TODO: Figure out how to display bitmaps at precise locations on screen
// TODO: grid is 8x8 spaces
// TODO: space size is 8x8 pixels
// TODO: Figure out if able to programmatically invert bitmaps -- if yes, use smaller bitmap char; otherwise swap with inverted when highlighted
// TODO: make queue 8 atoms long to make it easier to deal with the smaller board -- alternatively make the board 8 high by 12 (96) or 13 (104) wide
// TODO: Figure out how to represent each atom and molecule in Arduino because this ain't no JavaScript

Game game;

//Arduboy arduboy;

void setup() {
	game.setup();

//arduboy.begin();
//arduboy.setFrameRate(15);
}


void loop() {
	game.tick();

//if (!(arduboy.nextFrame())) {
//	return;
//}
//
//arduboy.clear();
//arduboy.setCursor(4, 9);
//
//arduboy.print(F("Hello, world!"));
//arduboy.display();
}
