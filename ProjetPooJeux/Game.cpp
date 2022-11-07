#include "Game.h"

Player player1("joueur1", 30, 0, 1);
Player player2("joueur1", 30, 0, 1);

Game::Game() {
}

bool Game::buyingPhase() {
	player1.getPlayerDeck();

}