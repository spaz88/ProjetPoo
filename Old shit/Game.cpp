#include "Game.h"
#include <stdlib.h>

Deck deck;
Player player1("joueur1", 20, 3, 1);
Player player2("joueur2", 20, 3, 1);

Deck tabDeck[2] = {player1.getPlayerDeck(), player2.getPlayerDeck()};

int prixLv = 10;

Game::Game()
{
	Game::topText();

	signed int playerChoice = 0;
	while (true)
	{
		// Player's choice
		std::cout << "1) Buy cards" << std::endl;
		std::cout << "2) Sell cards" << std::endl;
		std::cout << "3) Manage inventory" << std::endl;
		std::cout << "4) Skip buying phase" << std::endl;
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
			Game::manageInventory();
		}
		else if (playerChoice == 3)
		{
			Game::attackPhase(tabDeck);
		}
	}
}

// Function for the buying phase
void Game::buyingPhase()
{
	signed int playerChoice = 1;

	std::vector<Battlers> currentGameDeck = deck.getGameDeck();

	while (playerChoice != 0)
	{
		if (playerChoice < 8 || playerChoice > 0)
		{
			if (player1.getGold() > 0)
			{

				std::cout << "Choose which card you want from 1 to 6" << std::endl;
				std::cout << "Or choose 7 to upgrade your leveclel" << std::endl;

				// Here, we're upgrading the player's level in order to allow him to buy more powerfull battler
				/*prixLv--;
				int prixAffichage = player1.getLevel() + 1;
				std::cout << "The current cost to upgrade to lv " + std::to_string(prixAffnuichage) + " is " + std::to_string(prixLv) << std::endl;
				if(playerChoice == 7 && player1.getGold() > prixLv) {
					player1.setLevel(player1.getLevel() + 1);
				} else {
					std::cout << "LOOOL, you don't have enough gold for that, who u think u are è_é - looser";
				}*/

				// Display the player card
				std::vector<Battlers> currentGameDeck = deck.getGameDeck();
				for (int i = 0; i < currentGameDeck.size(); i++)
				{
					currentGameDeck[i].displayCard();
				}

				player1.diplayStats();

				std::cout << "Enter 0 to exit" << std::endl;

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
					tabDeck[0].addBattlersInventory(currentGameDeck[playerChoice - 1]);
					std::cout << "after addInventory" << std::endl;

					player1.setGold(player1.getGold() - currentGameDeck[playerChoice - 1].getPrice());
					std::cout << "after getPrice" << std::endl;

					std::cout << "Price : " << currentGameDeck[playerChoice - 1].getPrice() << std::endl;
					std::cout << "Money : " << player1.getGold() << std::endl;
				}
				std::cout << "after if 1" << std::endl;
			}
			std::cout << "after if 2" << std::endl;
			std::cout << "Do you want to buy another card ?" << std::endl;
			std::cin >> playerChoice;
		}
		else
		{
			std::cout << "Choose a valid number between 0 and 6" << std::endl;
		}
		std::cout << "after if 3" << std::endl;
	}
	std::cout << "after while" << std::endl;

	tabDeck[1].addBattlersPlayerDeck(currentGameDeck[0]);
	tabDeck[1].addBattlersPlayerDeck(currentGameDeck[1]);
}

// Selling phase function - Here, the player will be able to sell card in exchange of 1 gold
void Game::sellMode()
{

	std::vector<Battlers> currentPlayerInventory = tabDeck[0].getInventory();
	signed int playerChoice = 0;

	// We're displaying the user's cards
	for (int i = 0; i < (int)currentPlayerInventory.size(); i++)
	{
		currentPlayerInventory[i].displayCard();
	}

	std::cout << "Which card would you like to sell ?" << std::endl
			  << ": ";
	std::cin >> playerChoice;

	while (playerChoice != 0)
	{

		char answer[2];

		std::cout << "Do you really want to delete the " << playerChoice << " card ? (y/n)" << std::endl;
		std::cin >> answer;
		// Selling the battler after the validation
		if (answer[0] == 'y')
		{
			playerChoice -= 1;
			deck.removeBattlerInventory(playerChoice);
			// player1.setGold(player1.getGold() + currentPlayerDeck[playerChoice].getPrice());
			player1.setGold(player1.getGold() + 1); // Seeling only bring back1 gold
		}

		// We'll display the new deck (without the on we sold)
		std::vector<Battlers> currentPlayerInventory = deck.getPlayerDeck();

		for (int i = 0; i < (int)currentPlayerInventory.size(); i++)
		{
			currentPlayerInventory[i].displayCard();
		}
		player1.diplayStats();
		std::cout << "Which card would you like to sell ? (0 to exit)" << std::endl
				  << ": ";
		std::cin >> playerChoice;
	}
}

// Attack Phase - The combat is here
void Game::attackPhase(Deck tabDeck[])
{
	// make rand be random
	srand(time(NULL));
	int p1, p2, i, turn;
	// We are choosing which player will attack first
	p1 = rand() % 100;
	p2 = rand() % 100;
	i = 0;
	turn = 0;
	// making
	while (p1 == p2)
	{
		int p1 = rand() % 100;
		int p2 = rand() % 100;
	}

	std::cout << "p1 :" << p1 << std::endl;
	std::cout << "p2 :" << p2 << std::endl;
	std::cout << "p1deck :" << tabDeck[0].getPlayerDeck().size() << std::endl;
	std::cout << "p2deck :" << tabDeck[0].getPlayerDeck().size() << std::endl;

	while (tabDeck[0].getPlayerDeck().size() != 0 && tabDeck[1].getPlayerDeck().size() != 0) // while both players have battlers
	{
		int attackBattler = i;
		int randomVictim = rand() % tabDeck[i % 2].getPlayerDeck().size();

		if (p1 > p2)
		{
			// p1 attack first
			p1 = p2;
			tabDeck[1].getPlayerDeck()[randomVictim].setHealth(tabDeck[1].getPlayerDeck()[randomVictim].getHealth() - tabDeck[0].getPlayerDeck()[attackBattler].getDamage());
			if (tabDeck[1].getPlayerDeck()[randomVictim].getHealth() <= 0)
			{
				std::cout << tabDeck[0].getPlayerDeck()[attackBattler].getName() << " killed " << tabDeck[1].getPlayerDeck()[randomVictim].getName() << std::endl;
				tabDeck[1].removePlayerBattler(randomVictim);
			}
			checkWinner(tabDeck);
		}
		else
		{
			// vitctim take damage

			tabDeck[i % 2].getPlayerDeck()[randomVictim].setHealth(tabDeck[i % 2].getPlayerDeck()[randomVictim].getHealth() - tabDeck[abs(((i % 2) - 1))].getPlayerDeck()[attackBattler].getDamage());
			std::cout << tabDeck[0].getPlayerDeck()[attackBattler].getName() << " attacked " << tabDeck[1].getPlayerDeck()[randomVictim].getName() << std::endl;
			// attackant get victim damage if he is not dead and damage from vitcim are higher than the attackant damage
			if (tabDeck[i % 2].getPlayerDeck()[randomVictim].getHealth() > 0 && tabDeck[i % 2].getPlayerDeck()[randomVictim].getDamage() > tabDeck[abs(((i % 2) - 1))].getPlayerDeck()[attackBattler].getDamage())
			{
				// attackant get the difference between the damage of the victim and his own damage
				tabDeck[abs(((i % 2) - 1))].getPlayerDeck()[attackBattler].setHealth(tabDeck[abs(((i % 2) - 1))].getPlayerDeck()[attackBattler].getHealth() - (tabDeck[i % 2].getPlayerDeck()[randomVictim].getDamage() - tabDeck[abs(((i % 2) - 1))].getPlayerDeck()[attackBattler].getDamage()));
			}

			if (tabDeck[i % 2].getPlayerDeck()[randomVictim].getHealth() <= 0)
			{
				std::cout << tabDeck[abs((i % 2) - 1)].getPlayerDeck()[attackBattler].getName() << " killed " << tabDeck[i % 2].getPlayerDeck()[randomVictim].getName() << std::endl;
				tabDeck[i % 2].removePlayerBattler(randomVictim);
			}
			checkWinner(tabDeck);
			// p2 attack first
			// and basic combat
		}
		i++;
		// add tour
	} // p1 attack first
}

void Game::checkWinner(Deck tabDeck[])
{
	// check the win and the draw
	// Here, we're checking if a player still have battlers on the battlefield.
	if (tabDeck[0].getPlayerDeck().size() == 0 && tabDeck[1].getPlayerDeck().size() == 0)
	{
		std::cout << "Draw" << std::endl;
	}
	else if (tabDeck[0].getPlayerDeck().size() == 0)
	{
		std::cout << "Player 2 wins" << std::endl;
	}
	else if (tabDeck[1].getPlayerDeck().size() == 0)
	{
		std::cout << "Player 1 wins" << std::endl;
	}
	else
	{
		return;
	}
}

void Game::manageInventory()
{

	int playerChoice = 0;

	std::cout << "Inventory :" << std::endl;

	for (size_t i = 0; i < tabDeck[0].getPlayerDeck().size(); i++)
	{
		tabDeck[0].getPlayerDeck()[i].displayCard();
	}

	std::cout << "-------------------------------------------------------------------" << std::endl;

	for (size_t i = 0; i < tabDeck[0].getInventory().size(); i++)
	{
		tabDeck[0].getInventory()[i].displayCard();
	}

	std::cout << "Choose which card you want to play" << std::endl
			  << ": ";

	std::cin >> playerChoice;

	while (playerChoice != 0)
	{
		tabDeck[0].addBattlersPlayerDeck(tabDeck[0].getInventory()[playerChoice - 1]);

		std::cout << "Inventory :" << std::endl;

		for (size_t i = 0; i < tabDeck[0].getPlayerDeck().size(); i++)
		{
			tabDeck[0].getPlayerDeck()[i].displayCard();
		}

		std::cout << "-------------------------------------------------------------------" << std::endl;

		for (size_t i = 0; i < tabDeck[0].getInventory().size(); i++)
		{
			tabDeck[0].getInventory()[i].displayCard();
		}

		std::cout << "Choose which card you want to play" << std::endl
				  << ": ";

		std::cin >> playerChoice;
	}
}