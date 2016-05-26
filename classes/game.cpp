#include "../headers/config.h"
#include "../headers/board.h"
#include "../headers/generator.h"
#include "../headers/manifest.h"
#include "../headers/game.h"

Game::Game() {}

void Game::setup() {
	// TODO: setup game
	board = new Board();
	generator = new Generator(RANDOM_SEED_FLAG);
	manifest = new Manifest();
}

void Game::tick() {
	// TODO:
	// Generate atom
}
