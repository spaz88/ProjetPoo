#pragma once
#include "Player.h"
#include "Deck.h"
#include "Battlers.h"
class Game
{
public:
	Game();
	void buyingPhase();
	void attackPhase(Deck, Deck);
	void sellMode();

	void topText()
	{
		std::cout << "______             _____                      " << std::endl;
		std::cout << "| ___ \\           |  __ \\                     " << std::endl;
		std::cout << "| |_/ /__   ___   | |  \\ __ _ _ __ ___   ___ " << std::endl;
		std::cout << "|  __/ _ \\ / _ \\  | | __ / _` | '_ ` _ \\ / _ \\" << std::endl;
		std::cout << "| | | (_) | (_) | | |_\\ \\ (_| | | | | | |  __/" << std::endl;
		std::cout << "\\_|  \\___/ \\___/   \\____/\\__,_|_| |_| |_|\\___|" << std::endl;
		std::cout << "                                              " << std::endl;
		std::cout << "**********************************************" << std::endl;
	}
	void checkWinner(Deck, Deck);
};
