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

	std::vector<Battlers> getPlayerDeck() { return playerDeck; };
	void addBattlersPlayerDeck(Battlers battler) { playerDeck.push_back(battler); };
	void removePlayerBattler(int playerChoice) { playerDeck.erase(playerDeck.begin() + playerChoice); };
	std::vector<Battlers> getGameDeck() { return gameDeck; };
};
