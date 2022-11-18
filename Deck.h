#pragma once

#include "Battlers.h"
#include <vector>

class Deck
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
	void addBattlersPLayerDeck(Battlers battler) { playerDeck.push_back(battler); };
	void removePlayerBattler(int playerChoice) { playerDeck.erase(playerDeck.begin() + playerChoice); };
	std::vector<Battlers> getGameDeck(){return gameDeck;};
};

