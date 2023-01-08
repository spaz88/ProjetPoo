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
	bool gameOver();
	void startTurn();
private:
	std::vector<Player> m_players;
	std::vector<Battler> m_battlerList;
	int indexCurrentPlayer;
};
