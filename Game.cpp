#include "Game.h"
#include <stdlib.h>

Deck deck;
Player player1("joueur1", 20, 10, 1);
Player player2("joueur2", 20, 0, 1);

Deck deckPlayer1 = player1.getPlayerDeck();
Deck deckPlayer2 = player2.getPlayerDeck();

Game::Game()
{
	Game::topText();

	signed int playerChoice = 0;
	while (true)
	{

		std::cout << "1) Buy cards" << std::endl;
		std::cout << "2) Sell cards" << std::endl;
		std::cout << "3) Skip buying phase" << std::endl;
		std::cout << ": ";

		std::cin >> playerChoice;

		while (playerChoice < 1 && playerChoice > 3)
		{
			std::cout << playerChoice << " is not a valid number. Please enter a valid number (1, 2 or 3)" << std::endl;
			std::cout << ": " << std::endl;
			std::cin >> playerChoice;
		}

		if (playerChoice == 1)
		{
			Game::buyingPhase();
		}
		else if (playerChoice == 2)
		{
			Game::sellMode();
		}
		else if (playerChoice == 3)
		{
			Game::attackPhase(deckPlayer1, deckPlayer2);
			std::cout << "Test attack Phase passed" << std::endl;
		}
	}
}

// Function for the buying phase
void Game::buyingPhase()
{
	signed int playerChoice = 1;

	std::vector<Battlers> currentGameDeck = deck.getGameDeck();

	while (playerChoice != 0 && playerChoice < 7)
	{
		if (playerChoice < 6 || playerChoice >= 0)
		{
			if (player1.getGold() > 0)
			{

				std::cout << "Choose which card you want from 1 to 6" << std::endl;

				// Display the player card
				std::vector<Battlers> currentGameDeck = deck.getGameDeck();
				for (int i = 0; i < (int)currentGameDeck.size(); i++)
				{
					currentGameDeck[i].diplayCard();
				}
				player1.diplayStats();

				std::cout << std::endl
						  << "Enter 0 to exit" << std::endl;

				std::cin >> playerChoice;

				if (playerChoice == 0)
				{
					break;
				}

				// Buying - If the player have enough money to buy a battler :
				// -> We add the battler to the deck
				// -> We withdraw the money from the player
				// -> We display the user's datas
				if (player1.getGold() >= currentGameDeck[playerChoice - 1].getPrice())
				{
					deckPlayer1.addBattlersPlayerDeck(currentGameDeck[playerChoice - 1]);
					player1.setGold(player1.getGold() - currentGameDeck[playerChoice - 1].getPrice());
					std::cout << "Price : " << currentGameDeck[playerChoice - 1].getPrice() << std::endl;
					std::cout << "Money : " << player1.getGold() << std::endl;
				}
			}
		}
		else
		{
			std::cout << "Choose a valid number between 0 and 6" << std::endl;
		}
	}
	deckPlayer2.addBattlersPlayerDeck(currentGameDeck[0]);
	deckPlayer2.addBattlersPlayerDeck(currentGameDeck[1]);
}

// Selling phase function - Here, the player will be able to sell card in exchange of 1 gold
void Game::sellMode()
{

	std::vector<Battlers> currentPlayerDeck = deck.getPlayerDeck();
	signed int playerChoice = 0;

	// We're displaying the user's cards
	for (int i = 0; i < (int)currentPlayerDeck.size(); i++)
	{
		currentPlayerDeck[i].diplayCard();
	}

	std::cout << "Which card would you like to sell ?" << std::endl
			  << ": ";
	std::cin >> playerChoice;

	while (playerChoice != 0)
	{

		char answer;

		std::cout << "Do you really want to delete the " << playerChoice << " card ? (y/n)" << std::endl;
		std::cin >> answer;
		// Selling the battler after the validation
		if (answer == 'y')
		{
			playerChoice -= 1;
			deck.removePlayerBattler(playerChoice);
			// player1.setGold(player1.getGold() + currentPlayerDeck[playerChoice].getPrice());
			player1.setGold(player1.getGold() + 1); // Seeling only bring back1 gold
		}

		// We'll display the new deck (without the on we sold)
		std::vector<Battlers> currentPlayerDeck = deck.getPlayerDeck();

		for (int i = 0; i < (int)currentPlayerDeck.size(); i++)
		{
			currentPlayerDeck[i].diplayCard();
		}
		player1.diplayStats();
		std::cout << "Which card would you like to sell ? (0 to exit)" << std::endl
				  << ": ";
		std::cin >> playerChoice;
	}
}

// Attack Phase - The combat is here
void Game::attackPhase(Deck deckPlayer1, Deck deckPlayer2)	
{
	// make rand be random
	srand(time(NULL));
	int p1, p2, i,turn;
	// We're choosing which player will attack first
	p1 = rand() % 100;
	p2 = rand() % 100;
	i = 0;
	turn = 0;

	while(p1 == p2)
	{
		int p1 = rand() % 100;
		int p2 = rand() % 100;
	}

	std::cout << "p1 :" << p1 << std::endl;
	std::cout << "p2 :" << p2 << std::endl;
	std::cout << "p1deck :" << deckPlayer1.getPlayerDeck().size() << std::endl;
	std::cout << "p2deck :" << deckPlayer1.getPlayerDeck().size()<< std::endl;
	
	while (deckPlayer1.getPlayerDeck().size() != 0 && deckPlayer2.getPlayerDeck().size() != 0) // while both players have battlers
	{
		if (p1 > p2)
		{
					std::cout << "p1 > p2"<< std::endl;

			turn = 1;
		}
		std::cout << "before if % 2" << std::endl;
		if (turn % 2 != 0 || p1 > p2)
		{
			if (p1 != p2)
			{
				p1 = p2;
			}
			std::cout << "p1 :" << p1 << std::endl;
			std::cout << "p2 :" << p2 << std::endl;
			std::cout << "Player 1's turn" << std::endl;
			// choose the first battler from player 1's deck
			int randomBattler1 = i;
			// choose a random battler from player 2's deck
			int randomBattler2 = rand() % deckPlayer2.getPlayerDeck().size();
			// attack the random battler from player 2's deck
			deckPlayer2.getPlayerDeck()[randomBattler2].setHealth(deckPlayer2.getPlayerDeck()[randomBattler2].getHealth() - deckPlayer1.getPlayerDeck()[randomBattler1].getDamage());
			// if the health of the battler is 0 or less, remove it from the deck
			if (deckPlayer2.getPlayerDeck()[randomBattler2].getHealth() <= 0)
			{
				deckPlayer2.removePlayerBattler(randomBattler2);
			}
		checkWinner(deckPlayer1, deckPlayer2);
		}
		else
		{
			// if the deck is not empty, the player continues

			std::cout << "Player 2's turn" << std::endl;
			// choose a random battler from player 2's deck
			int randomBattler1 = rand() % deckPlayer2.getPlayerDeck().size();
			// choose a random battler from player 1's deck
			int randomBattler2 = rand() % deckPlayer1.getPlayerDeck().size();
			// attack the random battler from player 1's deck
			deckPlayer1.getPlayerDeck()[randomBattler2].setHealth(deckPlayer1.getPlayerDeck()[randomBattler2].getHealth() - deckPlayer2.getPlayerDeck()[randomBattler1].getDamage());
			checkWinner(deckPlayer1, deckPlayer2);
		}
		turn++;
	}
	std::cout << "end of attack phase" << std::endl;
}

void Game::checkWinner(Deck deckPlayer1,Deck deckPlayer2)
{
	// check the win and the draw
	if (deckPlayer1.getPlayerDeck().size() == 0 && deckPlayer2.getPlayerDeck().size() == 0) 
	{
		std::cout << "Draw" << std::endl;
	}
	else if (deckPlayer1.getPlayerDeck().size() == 0)
	{
		std::cout << "Player 2 wins" << std::endl;
	}
	else if (deckPlayer2.getPlayerDeck().size() == 0)
	{
		std::cout << "Player 1 wins" << std::endl;
	}
	else{
		return;
	}

}