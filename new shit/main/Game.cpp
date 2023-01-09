#include "Game.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <iostream>

Game::Game() {
	m_battlerList.push_back(Battler("truc1", 1, 10, 1, "goblin"));
	m_battlerList.push_back(Battler("truc2", 1, 10, 1, "goblin"));
	m_battlerList.push_back(Battler("truc3", 1, 10, 1, "goblin"));
	m_battlerList.push_back(Battler("truc4", 1, 10, 1, "goblin"));
	std::cout << m_battlerList.size() << std::endl;
	indexCurrentPlayer = 0;
	m_tabRandomBattlerNumber[9] = { 0 };
	refreshBattlerList();
	srand(time(0));
}

void Game::startGame()
{
	m_players.push_back(Player("Player 1", 3, 1, 20));
	m_players.push_back(Player("Player 2", 3, 1, 20));

	// Main game loop
	while (true)
	{
		// Check if the game has ended
		if (gameOver())
		{
			endGame();
			break;
		}

		// Start the current player's turn
		startTurn();
		std::cout << "Player n° : " << indexCurrentPlayer << std::endl;

		// End the current player's turn
		endTurn();
	}
}

void Game::startTurn()
{
	std::string choiceString;
	// Increment gold of current player
	m_players[indexCurrentPlayer].setGold(m_players[indexCurrentPlayer].getGold() + 1);

	while (choiceString != "q") {

		std::cout << "Press q pass to the next phase" << std::endl;

		// Prompt player to hire a battler
		std::cout << "Do you want to hire a battler? (Y/N/Q): ";

		//std::cout << m_players[indexCurrentPlayer].getHand().size() << std::endl;
		std::cin >> choiceString;

		if (choiceString == "Y" || choiceString == "y")
		{
			// Display battler options
			std::cout << "Battler Options:" << std::endl;

			for (int i = 0; i < 3; ++i)
			{
				std::cout << i + 1 << ". " << m_battlerList[m_tabRandomBattlerNumber[i]].getName() << std::endl;
			}
			std::cout << "Refresh ?(Y/N)";
			std::cin >> choiceString;
			if (choiceString == "Y" || choiceString == "y") {
				refreshBattlerList();
				for (int i = 0; i < 3; ++i)
				{
					std::cout << i + 1 << ". " << m_battlerList[m_tabRandomBattlerNumber[i]].getName() << std::endl;
				}
			}
			// Prompt player to choose a battler
			std::cout << "Choose a battler (1-3): ";
			int choice;
			std::cin >> choice;

			// Hire chosen battler
			hireBattler(m_battlerList[m_tabRandomBattlerNumber[choice -1]]);
		}

		// Check if current player can upgrade tavern
		if (m_players[indexCurrentPlayer].getGold() >= 5)
		{
			// Prompt player to upgrade Tavern
			std::cout << "Do you want to upgrade your Tavern? (Y/N/Q): ";
			std::cin >> choiceString;
			if (choiceString == "Y" || choiceString == "y")
			{
				upgradeTavern();
			}
		}
		else {
			std::cout << "Not enough gold to upgrade your Tavern" << std::endl;
		}

			// Prompt player to dismiss a battler
		std::cout << "Do you want to dismiss a battler? (Y/N/Q): ";
		std::cin >> choiceString;
		if (choiceString == "Y" || choiceString == "y")
		{
			// Display battler options
			std::cout << "Battler Options:" << std::endl;
			for (int i = 0; i < m_players[indexCurrentPlayer].getBattlers().size(); ++i)
			{
				std::cout << i + 1 << ". " << m_players[indexCurrentPlayer].getBattlers()[i].getName() << std::endl;
			}

			// Prompt player to choose a battler
			std::cout << "Choose a battler (1-" << m_players[indexCurrentPlayer].getBattlers().size() << "): ";
			int choice;
			std::cin >> choice;

			// Dismiss chosen battler
			dismissBattler(m_players[indexCurrentPlayer].getBattlers()[choice - 1]);
		}
	}
}

void Game::endTurn()
{
	std::cout << "Do you want to change your hand ?(Y/N)" << std::endl;
	std::string choice;
	std::cin >> choice;
	if ((choice == "N" || choice == "n") && m_players[indexCurrentPlayer].getHand().size() < 1) {
		std::cout << "You need to choose at least 1 Battler in you hand" << std::endl;
		choice = "y";
	}
	if (choice != "y" || choice != "Y") {
		while ((choice != "q" || choice != "Q") && m_players[indexCurrentPlayer].getHand().size() >= 1) {

			//Player can choose up to 4 Battlers in hand
			std::cout << "Choose up to 4 battlers to put in battle (Enter q to quit)" << std::endl;

			for (int i = 0; i < m_players[indexCurrentPlayer].getBattlers().size(); i++) {
				std::cout << i + 1 << ". " << m_players[indexCurrentPlayer].getBattlers()[i].getName() << std::endl;
			}
			std::cout << "Choose the battler you want to put in your hand" << std::endl;

			int choice;
			std::cin >> choice;
			m_players[indexCurrentPlayer].addToHand(m_players[indexCurrentPlayer].getBattlers()[choice - 1]);
		}
	}

	//Changes the indexCurrentPlayer between the 2 players
	if (indexCurrentPlayer == 0) {
		indexCurrentPlayer = 1;
	}
	else
	{
		indexCurrentPlayer = 0;
	}
}

void Game::endGame()
{
	// Determine the winner
	Player& winner = *std::max_element(m_players.begin(), m_players.end(), [](const Player& p1, const Player& p2) {
		return p1.getHP() < p2.getHP();
		});
	//compare player 2 health and player 1 health if equals to 0 



	// Print out the winner
	std::cout << winner.getName() << " has won the game!" << std::endl;
}

bool Game::gameOver()
{
	// Check if any player has 0 or fewer hit points
	return std::any_of(m_players.begin(), m_players.end(), [](const Player& player) {
		return player.getHP() <= 0;
		});
}

void Game::upgradeTavern()
{
	int cost = 5;
	if (m_players[indexCurrentPlayer].getTavernTier() < 4)
	{
		cost -= m_players[indexCurrentPlayer].getTavernTier();
	}

	if (m_players[indexCurrentPlayer].getGold() >= cost)
	{
		m_players[indexCurrentPlayer].setGold(m_players[indexCurrentPlayer].getGold() - cost);
		m_players[indexCurrentPlayer].setTavernTier(m_players[indexCurrentPlayer].getTavernTier() + 1);
	}
	else
	{
		std::cout << "Not enough gold to upgrade tavern" << std::endl;
	}
}

void Game::dismissBattler(Battler& b)
{
	// Find the battler in the current player's battlers and hand
	auto it = std::find(m_players[indexCurrentPlayer].getBattlers().begin(), m_players[indexCurrentPlayer].getBattlers().end(), b);
	if (it != m_players[indexCurrentPlayer].getBattlers().end())
	{
		// Remove the battler from the current player's battlers
		m_players[indexCurrentPlayer].getBattlers().erase(it);
	}
	else
	{
		it = std::find(m_players[indexCurrentPlayer].getHand().begin(), m_players[indexCurrentPlayer].getHand().end(), b);
		if (it != m_players[indexCurrentPlayer].getHand().end())
		{
			// Remove the battler from the current player's hand
			m_players[indexCurrentPlayer].getHand().erase(it);
		}
		else
		{
			// Battler not found in current player's battlers or hand
			return;
		}
	}

	// Return 1 gold to the current player
	m_players[indexCurrentPlayer].setGold(m_players[indexCurrentPlayer].getGold() + 1);
}

void Game::hireBattler(const Battler& battler)
{
	// Check if the player has enough gold to hire the battler
	if (m_players[indexCurrentPlayer].getGold() < 3)
	{
		std::cout << "Not enough gold to hire battler.\n";
		return;
	}

	// Check if the player has room in their hand to hire the battler
	if (m_players[indexCurrentPlayer].getBattlers().size() >= 6)
	{
		std::cout << "Player's battlers list is full. Cannot hire battler.\n";
		return;
	}

	// Hire the battler
	m_players[indexCurrentPlayer].addBattler(battler);
	m_players[indexCurrentPlayer].setGold(m_players[indexCurrentPlayer].getGold() - 3);
}

void Game::refreshBattlerList() {
	for (int i = 0; i < 3; i++) {
		m_tabRandomBattlerNumber[i] = rand() % m_battlerList.size();
	}
}