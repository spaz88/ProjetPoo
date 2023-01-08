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

	Deck playerDeck;
	Deck playerInventory;

public:
	Player(std::string name, int health, int gold, int level);
	Player();

	int getGold();
	int getHealth();
	int getLevel();
	Deck getPlayerDeck() { return playerDeck; };
	Deck getPlayerInventory() { return playerInventory; };

	void setGold(int newGold);
	void setHealth(int newHealth);
	void setLevel(int newLevel);

	void diplayStats();
};