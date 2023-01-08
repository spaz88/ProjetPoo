#include "Deck.h"
#include <vector>

Battlers battler1("goblin apprentice", 1, 10, 3);
Battlers battler2("hungry spider gang", 5, 3, 3);
Battlers battler3("skeleton troubadour", 8, 8, 3);
Battlers battler4("drunk dwarf", 4, 20, 3);
Battlers battler5("corrupted devil hunter", 10, 10, 3);
Battlers battler6("autistic dragon with one wing", 11, 30, 3);
Battlers battler7("baby spartiate", 4, 1, 3);
Battlers battler8("black shrek", 100, 100, 3);
Battlers battler9("Japaness 'flower aviator' from ww2", 100, 1, 3);
Battlers battler10("japonese UwU egirl", 1, 1, 3);
Battlers battler11("White cute Panthere", 5, 5, 3);
Battlers battlers12("Cuck du groupe 32", 0, 0, 3);
Battlers battlers13("Mage without wand", 1 , 4, 3);
Battlers battlers14("Blind archer", 2, 4, 3);
Battlers battlers15("The handsome Hercule but paraplegik", 2, 40, 3);
Battlers battlers16("The mad Butcher", 12, 12, 3);
Battlers battlers17("Steeve from minecraft", 7, 16, 3);
Battlers battlers18("Django but chained", 4, 9, 3);
Battlers battlers19("smartest student with alzheimer's", 5, 5, 3);
Battlers battlers20("Mermaid whithout gill",5, 2, 3);
Battlers battlers21("Thief without arm", 2, 2, 3);
// Battlers battlers23("Chinese samourai without leg", 4, 4, 3);

Deck::Deck()
{
	Deck::gameDeck.push_back(battler1);
	Deck::gameDeck.push_back(battler2);
	Deck::gameDeck.push_back(battler3);
	Deck::gameDeck.push_back(battler4);
	Deck::gameDeck.push_back(battler5);
	Deck::gameDeck.push_back(battler6);

	Deck::numberOfCards = Deck::playerDeck.size();
}
