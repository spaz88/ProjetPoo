#include "Game.h"
#include <stdlib.h>

Deck deck;
Player player1("joueur1", 30, 10, 1);
Player player2("joueur2", 30, 0, 1);

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

		if (playerChoice == 2)
		{
			Game::sellMode();
		}

		if (playerChoice == 3)
		{
			Game::attackPhase(player1.getPlayerDeck(), player2.getPlayerDeck());
		}
	}
}

void Game::buyingPhase()
{

	signed int playerChoice = 1;

	while (playerChoice != 0 && playerChoice < 7)
	{
		if (playerChoice < 6 || playerChoice >= 0)
		{
			if (player1.getGold() > 0)
			{

				std::cout << "Choose which card you want from 1 to 6" << std::endl;

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
	std::cout << deckPlayer1.getPlayerDeck().size() << std::endl;
	std::cout << deckPlayer2.getPlayerDeck().size() << std::endl;
}

void Game::sellMode()
{
	std::vector<Battlers> currentPlayerDeck = deck.getPlayerDeck();
	signed int playerChoice = 0;

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
		if (answer == 'y')
		{
			playerChoice -= 1;
			deck.removePlayerBattler(playerChoice);
			player1.setGold(player1.getGold() + currentPlayerDeck[playerChoice].getPrice());
		}

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

void Game::attackPhase(Deck deckPlayer1, Deck deckPlayer2)
{
	// make rand be random
	srand(time(NULL));
	int p1, p2;
	p1 = rand() % 100;
	p2 = rand() % 100;
	int turn = 0;
	while (p1 == p2)
	{
		int p1 = rand() % 100;
		int p2 = rand() % 100;
	}
	while(deckPlayer1.getPlayerDeck().size() != 0 && deckPlayer2.getPlayerDeck().size() != 0)// while both players have battlers
	{
		if (p1 > p2)
		{
			turn = 1;
		}
		else
		{
			turn = 2;
		}
		if (turn == 1)
		{
			std::cout << "Player 1's turn" << std::endl;
			// choose a random battler from player 1's deck
			int randomBattler = rand() % deckPlayer1.getPlayerDeck().size();
			// choose a random battler from player 2's deck
			int randomBattler2 = rand() % deckPlayer2.getPlayerDeck().size();
			// attack the random battler from player 2's deck
			deckPlayer2.getPlayerDeck()[randomBattler2].setHealth(deckPlayer2.getPlayerDeck()[randomBattler2].getHealth() - deckPlayer1.getPlayerDeck()[randomBattler].getAttack());
			// if the health of the battler is 0 or less, remove it from the deck
			if (deckPlayer2.getPlayerDeck()[randomBattler2].getHealth() <= 0)
			{
				deckPlayer2.removePlayerBattler(randomBattler2);
			}
			// if the deck is empty, the player loses
			if (deckPlayer2.getPlayerDeck().size() == 0)
			{
				std::cout << "Player 1 wins" << std::endl;
				break;
			}
			// if the deck is not empty, the player continues
			else
			{
				std::cout << "Player 2's turn" << std::endl;
				// choose a random battler from player 2's deck
				int randomBattler = rand() % deckPlayer2.getPlayerDeck().size();
				// choose a random battler from player 1's deck
				int randomBattler2 = rand() % deckPlayer1.getPlayerDeck().size();
				// attack the random battler from player 1's deck
				deckPlayer1.getPlayerDeck()[randomBattler2].setHealth(deckPlayer1.getPlayerDeck()[randomBattler2].getHealth() - deckPlayer2.getPlayerDeck()[randomBattler].getAttack());
				// if the health of the battler is 0
	{
		if (turn % 2 == 0 || p1 > p2)
		{
			if (p1 > p2)
				p1 = p2;

			deckPlayer2.getGameDeck()[r].setHealth(deckPlayer2.getGameDeck()[r].getHealth() - deckPlayer1.getGameDeck()[i].getDamage());
			if (deckPlayer2.getGameDeck()[0].getHealth() <= 0)
			{
				deckPlayer2.removePlayerBattler(0);
			}
			deckPlayer1.getGameDeck()[i].setHealth(deckPlayer1.getGameDeck()[i].getHealth() - deckPlayer2.getGameDeck()[r].getDamage());
			if (deckPlayer1.getGameDeck()[0].getHealth() <= 0)
			{
				deckPlayer1.removePlayerBattler(0);
			}
			turn++;
		}
		else
		{
			deckPlayer1.getGameDeck()[0].setHealth(deckPlayer1.getGameDeck()[0].getHealth() - deckPlayer2.getGameDeck()[0].getDamage());
			if (deckPlayer1.getGameDeck()[0].getHealth() <= 0)
			{
				deckPlayer1.removePlayerBattler(0);
			}
			deckPlayer2.getGameDeck()[0].setHealth(deckPlayer2.getGameDeck()[0].getHealth() - deckPlayer1.getGameDeck()[0].getDamage());
			if (deckPlayer2.getGameDeck()[0].getHealth() <= 0)
			{
				deckPlayer2.removePlayerBattler(0);
			}
						turn++;

		}
	}

	if (deckPlayer1.getGameDeck().size() == 0 && deckPlayer1.getGameDeck().size() == 0)
		std::cout << "DRAW" << std::endl;

	else if (deckPlayer1.getGameDeck().size() == 0)
		std::cout << "Player 2 win" << std::endl;

	else
		std::cout << "Player 1 win" << std::endl;
}
