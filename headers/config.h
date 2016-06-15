#ifndef CONFIG_H
#define CONFIG_H

// Clock directions for Atom bonds
const int ATOM_BOND_NORTH = 12;
const int ATOM_BOND_EAST = 3;
const int ATOM_BOND_SOUTH = 6;
const int ATOM_BOND_WEST = 9;

// Width and height of board in cells
const int BOARD_HEIGHT = 8;
const int BOARD_WIDTH = 8;

// Width and height of chars in pixels
const int CHAR_HEIGHT = 8;
const int CHAR_WIDTH = 8;

// Framerate of renderer
const int FRAMERATE = 15;

// Generator timer settings
const int GENERATOR_MILLIS_INIT = 5000; // Generator timer initial tick length
const int GENERATOR_MULLIS_MIN = 500; // Generator timer minimum tick length
const int GENERATOR_MILLIS_STEP = 500; // Generator timer step size
const int GENERATOR_STEP_ITERATIONS = 5; // Shorten the Generator tick length after this many completed molecules

// Queue length
const int QUEUE_LENGTH = 8;

// Whether to seed the RNG for debug
const bool RANDOM_SEED_DEBUG = true;
const int RANDOM_SEED_VALUE = 100; // Value to seed RNG with for repeatability

// Whether to output debug info to the Serial console;
const bool SERIAL_DEBUG = true;
const int SERIAL_DEBUG_INTERVAL = 1000;

// Number of points per bond
const int SCORE_MULTIPLIER = 100;

#endif
