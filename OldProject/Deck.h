#pragma once

#include "Battlers.h"
#include <vector>

class Deck
{
private:
	std::vector<Battlers> playerDeck;
	std::vector<Battlers> gameDeck;
	std::vector<Battlers> PlayerInventory;
	size_t numberOfCards;

public:
	Deck();

	std::vector<Battlers> getPlayerDeck() { return playerDeck; };

	std::vector<Battlers> getInventory() { return PlayerInventory; };

	void addBattlersPlayerDeck(Battlers battler) { playerDeck.push_back(battler); };
	void removePlayerBattler(int playerChoice) { playerDeck.erase(playerDeck.begin() + playerChoice); };

	void addBattlersInventory(Battlers battler) { PlayerInventory.push_back(battler); };
	void removeBattlerInventory(int playerChoice) { PlayerInventory.erase(PlayerInventory.begin() + playerChoice); };

	std::vector<Battlers> getGameDeck() { return gameDeck; };
};
