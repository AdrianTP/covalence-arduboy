/*
Buttons example
June 11, 2015
Copyright (C) 2015 David Martinez
All rights reserved.
This code is the most basic barebones code for showing how to use buttons in
Arduboy.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
*/

#include "Arduino.h"
#include "Arduboy.h"
#include "atom_bitmaps.h"
#include "headers/config.h"
#include "headers/atom.h"
#include "headers/board.h"
#include "headers/generator.h"
#include "headers/manifest.h"
#include "headers/game.h"

// TODO:
// arrow buttons change cursor location
// if cursor empty
	// remove first atom from queue and place in cursor location
// else
	// swap atoms

// TODO: Figure out how to display bitmaps at precise locations on screen
// TODO: grid is 8x8 spaces
// TODO: space size is 8x8 pixels
// TODO: Figure out if able to programmatically invert bitmaps -- if yes, use smaller bitmap char; otherwise swap with inverted when highlighted
// TODO: make queue 8 atoms long to make it easier to deal with the smaller board -- alternatively make the board 8 high by 12 (96) or 13 (104) wide
// TODO: Figure out how to represent each atom and molecule in Arduino because this ain't no JavaScript

Game game;

void setup() {
	game.setup();
}


void loop() {
	game.tick();
}
