#include "Deck.h"

Deck::Deck() {
	Battlers battler1("number1", 1, 10, 3);
	Battlers battler2("number2", 1, 10, 3);
	Battlers battler3("number3", 1, 10, 3);
	Battlers battler4("number4", 1, 10, 3);
	Battlers battler5("number5", 1, 10, 3);
	Battlers battler6("number6", 1, 10, 3);

	gameDeck.push_back(battler1);
	gameDeck.push_back(battler2);
	gameDeck.push_back(battler3);
	gameDeck.push_back(battler4);
	gameDeck.push_back(battler5);
	gameDeck.push_back(battler6);

	numberOfCards = playerDeck.size();
}