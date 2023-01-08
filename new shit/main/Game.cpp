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
}

void Game::startGame()
{
	m_players.push_back(Player("Player 1", 3, 1, 20));
    m_players.push_back(Player("Player 2", 3, 1, 20));

    // Set the current player to the first player in the list
    indexCurrentPlayer = 0;

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
    // Increment gold of current player
    m_players[indexCurrentPlayer].setGold(m_players[indexCurrentPlayer].getGold() + 1);

    // Check if current player has less than 4 battlers
    if (m_players[indexCurrentPlayer].getHand().size() < 4)
    {
        // Prompt player to hire a battler
        std::cout << "Do you want to hire a battler? (Y/N): ";
        //std::cout << m_players[indexCurrentPlayer].getHand().size() << std::endl;
        std::string choice;
        std::cin >> choice;
        if (choice == "Y" || choice == "y")
        {
            // Display battler options
            std::cout << "Battler Options:" << std::endl;
            for (int i = 0; i < 3; ++i)
            {
                std::cout << i + 1 << ". " << m_battlerList[i].getName() << std::endl;
            }

            // Prompt player to choose a battler
            std::cout << "Choose a battler (1-3): ";
            int choice;
            std::cin >> choice;

            // Hire chosen battler
            hireBattler(m_battlerList[choice-1]);
        }
    }
    // Check if current player can upgrade tavern
    if (m_players[indexCurrentPlayer].getGold() >= 5)
    {
        // Prompt player to upgrade Tavern
        std::cout << "Do you want to upgrade your Tavern? (Y/N): ";
        std::string choice;
        std::cin >> choice;
        if (choice == "Y" || choice == "y")
        {
            upgradeTavern();
        }
    }
    else {
        std::cout << "Not enough gold to upgrade your Tavern" << std::endl;
    }

    // Check if current player has more than 6 battlers
    if (m_players[indexCurrentPlayer].getBattlers().size() > 6)
    {
        // Prompt player to dismiss a battler
        std::cout << "Do you want to dismiss a battler? (Y/N): ";
        std::string choice;
        std::cin >> choice;
        if (choice == "Y" || choice == "y")
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
    // Increase the current player's gold by 1
    m_players[indexCurrentPlayer].addGold(1);

    // Increment the current player index, wrapping around to 0 if necessary
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
    if (m_players[indexCurrentPlayer].getHand().size() >= 6)
    {
        std::cout << "Hand is full. Cannot hire battler.\n";
        return;
    }

    // Hire the battler
    m_players[indexCurrentPlayer].addToHand(battler);
    m_players[indexCurrentPlayer].setGold(m_players[indexCurrentPlayer].getGold() - 3);
}
