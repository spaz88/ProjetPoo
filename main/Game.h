#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Battler.h"

class Game
{
public:
	Game(); // Constructor

	void hireBattler(const Battler& battler); // hire a battler
	void dismissBattler(Battler& battler); // dismiss a battler
	void refreshBattlerList(); // refresh the list of battlers
	void upgradeTavern(); // upgrade the tavern
	void startGame(); // start the game
	void endTurn(); // end the turn
	void endGame(); // end the game
	void startTurn(); // start the turn
	void attackTurn(); // attack turn
	void checkTier(); // check the TavernTier of player and add battler depeding of the tier

	int calculateHpLost(std::vector<Battler> playerBattler); // calculate the hp lost

	bool gameOver(); // check if the game is over

	void clearConsole()	//Display function
	{
#if defined(_WIN32)
		{ system("cls"); 
		std::cout << "Player : " << m_players[indexCurrentPlayer].getName() << "	Turn : " << m_turn << "	Money : " << m_players[indexCurrentPlayer].getGold() << "	Tavern tier : " << m_players[indexCurrentPlayer].getTavernTier() <<"		HP : " << m_players[indexCurrentPlayer].getHP() << std::endl; }
#elif defined(__linux__)
		{ system("clear"); std::cout << "Player : " << m_players[indexCurrentPlayer].getName() << "	Turn : " << m_turn << "	Money : " << m_players[indexCurrentPlayer].getGold() << "	Tavern tier : " << m_players[indexCurrentPlayer].getTavernTier() <<"	HP : " << m_players[indexCurrentPlayer].getHP() std::endl; }
	}
#endif;
	}

private:
	std::vector<Player> m_players;
	std::vector<Battler> m_battlerList;
	int indexCurrentPlayer;
	int m_tabRandomBattlerNumber[10];
	int m_turn;
};
