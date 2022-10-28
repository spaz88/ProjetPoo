#pragma once
#include <iostream>
#include <vector>

#include "Battlers.h"
class Player
{
private:
	int health;
	int gold;
	int level;

	std::vector<Battlers> playerBattlers;

	std::string name;

public:
	Player(std::string name, int health, int gold, int level, std::vector<Battlers> playerBattlers);

	int getGold();
	int getHealth();
	int getLevel();
	std::vector<Battlers> getPlayerBattlers();

	void setGold(int newGold);
	void setHealth(int newHealth);
	void setLevel(int newLevel);
	void setPlayerBattlers(std::vector<Battlers> newPlayerBattlers);

};