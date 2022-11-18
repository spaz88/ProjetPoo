#include "Deck.h"

Battlers battler1("number1", 1, 10, 3);
Battlers battler2("number2", 1, 10, 3);
Battlers battler3("number3", 1, 10, 3);
Battlers battler4("number4", 1, 10, 3);
Battlers battler5("number5", 1, 10, 3);
Battlers battler6("number6", 1, 10, 3);

Deck::Deck() {
	Deck::gameDeck.push_back(battler1);
	Deck::gameDeck.push_back(battler2);
	Deck::gameDeck.push_back(battler3);
	Deck::gameDeck.push_back(battler4);
	Deck::gameDeck.push_back(battler5);
	Deck::gameDeck.push_back(battler6);

	Deck::numberOfCards = Deck::playerDeck.size();
}
