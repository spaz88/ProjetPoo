#include "Deck.h"

Deck::Deck() {
	gameDeck.push_back(battler1);
	gameDeck.push_back(battler2);
	gameDeck.push_back(battler3);
	gameDeck.push_back(battler4);
	gameDeck.push_back(battler5);
	gameDeck.push_back(battler6);

	numberOfCards = playerDeck.size();
}