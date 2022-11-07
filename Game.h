#pragma once
#include "Player.h"
#include "Deck.h"
#include "Battlers.h"
class Game 
{
public:
	Game();
	bool buyingPhase();
	bool attackPhase();
};

