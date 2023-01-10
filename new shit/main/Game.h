#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Battler.h"

class Game
{
public:
	Game();

	void hireBattler(const Battler& battler);
	void dismissBattler(Battler& battler);
	void refreshBattlerList();
	void upgradeTavern();
	void startGame();
	void endTurn();
	void endGame();
	void startTurn();
	void attackTurn();
	void checkTier();

	int calculateHpLost(std::vector<Battler> playerBattler);

	bool gameOver();

	void clearConsole() {
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
