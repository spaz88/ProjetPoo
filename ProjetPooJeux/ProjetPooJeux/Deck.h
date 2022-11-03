#pragma once

#include "Battlers.h"
#include <vector>

class Deck
{
private:
	std::vector<Battlers> playerDeck;
	std::vector<Battlers> gameDeck;
	int numberOfCards;

public:
	Deck();

	void removeBattlers(int i) { playerDeck.erase(playerDeck.begin() + i); };
	void addBattler(int i) { playerDeck.push_back(gameDeck[i]); };
};

