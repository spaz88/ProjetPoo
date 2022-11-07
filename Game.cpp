#include "Game.h"

Deck deck;
Player player1("joueur1", 30, 0, 1);
Player player2("joueur2", 30, 0, 1);

Game::Game() {

}

bool Game::buyingPhase() {
	player1.getPlayerDeck();
	std::cout<<"Choose which card you want"<<std::endl;

	std::vector<Battlers> currentGameDeck = deck.getGameDeck();
	for(int i = 0; i < currentGameDeck.size(); i++){
		currentGameDeck[i].diplayCard();
	}
}