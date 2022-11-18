#include "Game.h"

Deck deck;
Player player1("joueur1", 30, 10, 1);
Player player2("joueur2", 30, 0, 1);

Game::Game() {
	Game::topText();

	signed int playerChoice = 0;
	while (true) {

		std::cout << "1) Buy cards" << std::endl;
		std::cout << "2) Sell cards" << std::endl;
		std::cout << "3) Skip buying phase" << std::endl;
		std::cout << ": ";

		std::cin >> playerChoice;

		while (playerChoice < 1 && playerChoice > 3) {
			std::cout << playerChoice << " is not a valid number. Please enter a valid number (1, 2 or 3)" << std::endl;
			std::cout << ": " << std::endl;
			std::cin >> playerChoice;
		}

		if (playerChoice == 1) {
			Game::buyingPhase();
		}

		if (playerChoice == 2) {
			Game::sellMode();
		}

		if (playerChoice == 3) {
			Game::attackPhase();
		}
	}
}

bool Game::buyingPhase() {

	signed int playerChoice = 1;

	while (playerChoice != 0 && playerChoice < 7) {
		if (playerChoice < 6 || playerChoice >= 0) {
			if (player1.getGold() > 0) {

				std::cout << "Choose which card you want from 1 to 6" << std::endl;

				std::vector<Battlers> currentGameDeck = deck.getGameDeck();
				for (int i = 0; i < currentGameDeck.size(); i++) {
					currentGameDeck[i].diplayCard();
				}																		//problem : la carte 1 (2) se met automatiauement dedan car initialise a 1, faire un condition pour rentrer un nombre entre 0 et 6
				player1.diplayStats();


				std::cout << std::endl << "Enter 0 to exit" << std::endl;

				std::cin >> playerChoice;

				if (playerChoice == 0) {
					break;
				}

				if (player1.getGold() >= currentGameDeck[playerChoice-1].getPrice()) {
					deck.addBattlersPLayerDeck(currentGameDeck[playerChoice-1]);
					player1.setGold(player1.getGold() - currentGameDeck[playerChoice-1].getPrice());
				}
				
			}
		}
		else {
			std::cout << "Choose a valid number between 0 and 6" << std::endl;
		}

	}
	return 1;
}

bool Game::attackPhase() {
	std::vector<Battlers> currentPlayerDeck = deck.getPlayerDeck();

	for (int i = 0; i < currentPlayerDeck.size(); i++) {
		currentPlayerDeck[i].diplayCard();
	}
	return 1;
}

void Game::sellMode() {
	std::vector<Battlers> currentPlayerDeck = deck.getPlayerDeck();
	signed int playerChoice = 0;

	for (int i = 0; i < currentPlayerDeck.size(); i++) {
		currentPlayerDeck[i].diplayCard();
	}

	std::cout << "Which card would you like to sell ?" << std::endl << ": ";
	std::cin >> playerChoice;

	while (playerChoice != 0) {

		char answer;

		std::cout << "Do you really want to delete the " << playerChoice << " card ? (y/n)" << std::endl;
		std::cin >> answer;
		if (answer == 'y') {
			playerChoice -= 1;
			deck.removePlayerBattler(playerChoice);
			player1.setGold(player1.getGold() + currentPlayerDeck[playerChoice].getPrice());
		}

		std::vector<Battlers> currentPlayerDeck = deck.getPlayerDeck();

		for (int i = 0; i < currentPlayerDeck.size(); i++) {
			currentPlayerDeck[i].diplayCard();
		}
		player1.diplayStats();
		std::cout << "Which card would you like to sell ? (0 to exit)" << std::endl << ": ";
		std::cin >> playerChoice;
	}

}