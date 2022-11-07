#pragma once

#include "Battlers.h"
#include <vector>

class Deck
{
private:
	std::vector<Battlers> playerDeck;
	std::vector<Battlers> gameDeck;
	size_t numberOfCards;

	Battlers battler1("number1", 1, 10, 3);
	Battlers battler2("number2", 1, 10, 3);
	Battlers battler3("number3", 1, 10, 3);
	Battlers battler4("number4", 1, 10, 3);
	Battlers battler5("number5", 1, 10, 3);
	Battlers battler6("number6", 1, 10, 3);

public:
	Deck();

	void removeBattlers(int i) { playerDeck.erase(playerDeck.begin() + i); };
	void addBattler(int i) { playerDeck.push_back(gameDeck[i]); };
};

