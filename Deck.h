#pragma once

#include "Battlers.h"
#include <vector>

class Deck : public Battlers
{
private:
	std::vector<Battlers> playerDeck;
	std::vector<Battlers> gameDeck;
	size_t numberOfCards;

public:
	Deck();

	void removeBattlers(int i) { playerDeck.erase(playerDeck.begin() + i); };
	void addBattler(int i) { playerDeck.push_back(gameDeck[i]); };

	std::vector<Battlers> getPlayerDeck(){return playerDeck;};
	void setPlayerDeck(Battlers battler, int i);
	std::vector<Battlers> getGameDeck(){return gameDeck;};
};

