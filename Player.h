#pragma once
#include <iostream>
#include <vector>

#include "Deck.h"
class Player
{
private:

	int health;
	int gold;
	int level;

	std::string name;

public:
	Player(std::string name, int health, int gold, int level);
	Player();

	Deck playerDeck;

	int getGold();
	int getHealth();
	int getLevel();
	Deck getPlayerDeck() { return playerDeck; };

	void setGold(int newGold);
	void setHealth(int newHealth);
	void setLevel(int newLevel);


	void diplayStats();

};