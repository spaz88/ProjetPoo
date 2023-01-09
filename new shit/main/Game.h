#pragma once
#include <string>
#include <vector>
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

	int calculateHpLost(std::vector<Battler> playerBattler);

	bool gameOver();

private:
	std::vector<Player> m_players;
	std::vector<Battler> m_battlerList;
	int indexCurrentPlayer;
	int m_tabRandomBattlerNumber[10];
	int m_turn;
};
