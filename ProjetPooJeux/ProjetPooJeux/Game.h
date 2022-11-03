#pragma once
#include "Player.h"
class Game : public Player
{
public:
	Game();
	bool buyingPhase();
	bool attackPhase();
};

