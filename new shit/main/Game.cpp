#include "Game.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <numeric>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

Game::Game() {
	m_players.push_back(Player("Player 1", 100, 1, 1));
	m_players.push_back(Player("Player 2", 100, 1, 1));

	checkTier();

	indexCurrentPlayer = 0;
	m_tabRandomBattlerNumber[9] = { 0 };
	refreshBattlerList();
	srand(time(0));
}

void Game::startGame()
{

	// Main game loop
	while (true)
	{
		// Check if the game has ended
		if (gameOver())
		{
			endGame(); // ne fini pas le jeu
			break;
		}

		// Start the current player's turn
		startTurn();

		// End the current player's turn
		endTurn();
	}
}

void Game::startTurn()
{
	checkTier();

	std::string choiceString;

	clearConsole();

	while (true) {

		// Prompt player to hire a battler
		std::cout << "Do you want to hire a battler? (Y/N): ";

		//std::cout << m_players[indexCurrentPlayer].getHand().size() << std::endl;
		std::cin >> choiceString;

		if (choiceString == "Y" || choiceString == "y")
		{
			// Display battler options
			std::cout << "Battler Options:" << std::endl;

			for (int i = 0; i < 3; ++i)
			{
				std::cout << i + 1 << ". " << m_battlerList[m_tabRandomBattlerNumber[i]].getName() << std::endl;
			}
			std::cout << "Refresh ?(Y/N)";
			std::cin >> choiceString;
			if (choiceString == "Y" || choiceString == "y") {
				refreshBattlerList();
				for (int i = 0; i < 3; ++i)
				{
					std::cout << i + 1 << ". " << m_battlerList[m_tabRandomBattlerNumber[i]].getName() << std::endl;
				}
			}
			// Prompt player to choose a battler
			std::cout << "Choose a battler (1-3): ";
			int choice;
			std::cin >> choice;

			// Hire chosen battler
			hireBattler(m_battlerList[m_tabRandomBattlerNumber[choice - 1]]);
			clearConsole();
		}

		// Check if current player can upgrade tavern
		if (m_players[indexCurrentPlayer].getGold() >= 5)
		{
			// Prompt player to upgrade Tavern
			std::cout << "Do you want to upgrade your Tavern? (Y/N): ";
			std::cin >> choiceString;
			if (choiceString == "Y" || choiceString == "y")
			{
				upgradeTavern();
			}
		}
		else {
			std::cout << "Not enough gold to upgrade your Tavern" << std::endl;
		}

		// Prompt player to dismiss a battler
		std::cout << "Do you want to dismiss a battler? (Y/N): ";
		std::cin >> choiceString;
		if (choiceString == "Y" || choiceString == "y")
		{
			// Display battler options
			std::cout << "Battler Options:" << std::endl;
			for (int i = 0; i < m_players[indexCurrentPlayer].getBattlers().size(); ++i)
			{
				std::cout << i + 1 << ". " << m_players[indexCurrentPlayer].getBattlers()[i].getName() << std::endl;
			}

			// Prompt player to choose a battler
			std::cout << "Choose a battler (1-" << m_players[indexCurrentPlayer].getBattlers().size() << "): ";
			int choice;
			std::cin >> choice;

			// Dismiss chosen battler
			dismissBattler(m_players[indexCurrentPlayer].getBattlers()[choice - 1]);
		}
		clearConsole();
		std::cout << "Finish buying ? (Y/N)";
		std::cin >> choiceString;
		if (choiceString == "Y" || choiceString == "y") {
			break;
		}
	}
}

void Game::endTurn()
{
	clearConsole();
	std::cout << "Do you want to change your hand ?(Y/N)" << std::endl;
	std::string choiceString;
	std::cin >> choiceString;
	if ((choiceString == "N" || choiceString == "n") && m_players[indexCurrentPlayer].getHand().size() < 1) {
		std::cout << "You need to choose at least 1 Battler in you hand" << std::endl;
		choiceString = "y";
	}
	if (choiceString == "y" || choiceString == "Y") {
		while (true) {

			clearConsole();
			//Player can choose up to 4 Battlers in hand
			std::cout << "Choose up to 4 battlers to put in battle (Enter q to quit)" << std::endl;
			std::cout << "Battler list : " << std::endl;

			for (int i = 0; i < m_players[indexCurrentPlayer].getBattlers().size(); i++) {
				std::cout << i + 1 << ". " << m_players[indexCurrentPlayer].getBattlers()[i].getName() << std::endl;
			}

			std::cout << "Your hand : " << std::endl;

			for (int i = 0; i < m_players[indexCurrentPlayer].getHand().size(); i++) {
				std::cout << i + 1 << ". " << m_players[indexCurrentPlayer].getHand()[i].getName() << std::endl;
			}
			std::cout << "Choose the battler you want to put in your hand" << std::endl;

			int choice;
			std::cin >> choice;
			m_players[indexCurrentPlayer].addToHand(m_players[indexCurrentPlayer].getBattlers()[choice - 1]);
			m_players[indexCurrentPlayer].getBattlers().erase(m_players[indexCurrentPlayer].getBattlers().begin() + choice - 1);

			std::cout << "Finish adding to hand ?" << std::endl;
			std::cin >> choiceString;
			if (choiceString == "y" || choiceString == "Y") {
				break;
			}
		}
	}
	std::cout << "Do you want to remove Battlers from your hand ?(Y/N)" << std::endl;
	std::cin >> choiceString;
	if (choiceString == "y" || choiceString == "Y") {
		while (true) {

			if (m_players[indexCurrentPlayer].getHand().size() <= 0) {
				std::cout << "You must have at least 1 battler in your hand !" << std::endl;
				break;
			}
			clearConsole();

			std::cout << "Battler list : " << std::endl;

			for (int i = 0; i < m_players[indexCurrentPlayer].getBattlers().size(); i++) {
				std::cout << i + 1 << ". " << m_players[indexCurrentPlayer].getBattlers()[i].getName() << std::endl;
			}

			std::cout << "Your hand : " << std::endl;

			for (int i = 0; i < m_players[indexCurrentPlayer].getHand().size(); i++) {
				std::cout << i + 1 << ". " << m_players[indexCurrentPlayer].getHand()[i].getName() << std::endl;
			}
			std::cout << "Choose the battlers you want to remove from your hand (Enter q to quit)" << std::endl;

			int choice;
			std::cin >> choice;
			m_players[indexCurrentPlayer].addBattler(m_players[indexCurrentPlayer].getBattlers()[choice - 1]);
			m_players[indexCurrentPlayer].removeFromHand(m_players[indexCurrentPlayer].getBattlers()[choice - 1]);

			std::cout << "Finish turn ?" << std::endl;
			std::cin >> choiceString;
			if (choiceString == "y" || choiceString == "Y") {
				break;
			}
		}
	}


	// Increment gold of current player
	m_players[indexCurrentPlayer].setGold(m_players[indexCurrentPlayer].getGold() + 2 + m_turn);

	if (indexCurrentPlayer == 1) {
		attackTurn();
		m_turn++;
	}

	//Changes the indexCurrentPlayer between the 2 players
	if (indexCurrentPlayer == 0) {
		indexCurrentPlayer = 1;
	}
	else
	{
		indexCurrentPlayer = 0;
	}
}

void Game::endGame()
{
	// Determine the winner
	Player& winner = *std::max_element(m_players.begin(), m_players.end(), [](const Player& p1, const Player& p2) {
		return p1.getHP() < p2.getHP();
		});
	//compare player 2 health and player 1 health if equals to 0 



	// Print out the winner
	std::cout << winner.getName() << " has won the game!" << std::endl;
}

bool Game::gameOver()
{
	// Check if any player has 0 or fewer hit points
	return std::any_of(m_players.begin(), m_players.end(), [](const Player& player) {
		return player.getHP() <= 0;
		});
}

void Game::upgradeTavern()
{
	int cost = 5;
	if (m_players[indexCurrentPlayer].getTavernTier() < 4)
	{
		cost -= m_players[indexCurrentPlayer].getTavernTier();
	}

	if (m_players[indexCurrentPlayer].getGold() >= cost)
	{
		m_players[indexCurrentPlayer].setGold(m_players[indexCurrentPlayer].getGold() - cost);
		m_players[indexCurrentPlayer].setTavernTier(m_players[indexCurrentPlayer].getTavernTier() + 1);
		std::cout << "Tavern upgraded to lvl " << m_players[indexCurrentPlayer].getTavernTier() << " . You'll see new tier in your shot next turn !" << std::endl;
	}
	else
	{
		std::cout << "Not enough gold to upgrade tavern" << std::endl;
	}
}

void Game::dismissBattler(Battler& b)
{
	// Find the battler in the current player's battlers and hand
	auto it = std::find(m_players[indexCurrentPlayer].getBattlers().begin(), m_players[indexCurrentPlayer].getBattlers().end(), b);
	if (it != m_players[indexCurrentPlayer].getBattlers().end())
	{
		// Remove the battler from the current player's battlers
		m_players[indexCurrentPlayer].getBattlers().erase(it);
	}
	else
	{
		it = std::find(m_players[indexCurrentPlayer].getHand().begin(), m_players[indexCurrentPlayer].getHand().end(), b);
		if (it != m_players[indexCurrentPlayer].getHand().end())
		{
			// Remove the battler from the current player's hand
			m_players[indexCurrentPlayer].getHand().erase(it);
		}
		else
		{
			// Battler not found in current player's battlers or hand
			return;
		}
	}

	// Return 1 gold to the current player
	m_players[indexCurrentPlayer].setGold(m_players[indexCurrentPlayer].getGold() + 1);
}

void Game::hireBattler(const Battler& battler)
{
	// Check if the player has enough gold to hire the battler
	if (m_players[indexCurrentPlayer].getGold() < 3)
	{
		std::cout << "Not enough gold to hire battler.\n";
		return;
	}

	// Check if the player has room in their hand to hire the battler
	if (m_players[indexCurrentPlayer].getBattlers().size() >= 6)
	{
		std::cout << "Player's battlers list is full. Cannot hire battler.\n";
		return;
	}

	// Hire the battler
	m_players[indexCurrentPlayer].addBattler(battler);
	m_players[indexCurrentPlayer].setGold(m_players[indexCurrentPlayer].getGold() - 3);
}

void Game::refreshBattlerList() {
	for (int i = 0; i < 3; i++) {
		m_tabRandomBattlerNumber[i] = rand() % m_battlerList.size();
	}
}

void Game::attackTurn() {

	std::cout << "Entering combat phase !" << std::endl;

	int p1 = rand() % 100;
	int p2 = rand() % 100;

	std::vector<Battler> P1Hand = m_players[0].getHand();
	std::vector<Battler> P2Hand = m_players[1].getHand();

	while (p1 == p2)
	{
		int p1 = rand() % 100;
		int p2 = rand() % 100;
	}

	if (p1 > p2) {

		while ((P1Hand.empty() == false) && (P2Hand.empty() == false)) {
			int randomOponent = rand() % P1Hand.size();
			int randomVictim = rand() % P2Hand.size();

			std::cout << "Player : 1 attacks " << P2Hand[randomVictim].getName() << " and deals " << P1Hand[randomOponent].getAttackDmg() << " Damages" << std::endl;

			P2Hand[randomVictim].setHealth(P2Hand[randomVictim].getHealth() - P1Hand[randomOponent].getAttackDmg());

			Sleep(1000);

			if (P2Hand[randomVictim].getHealth() <= 0) {
				P2Hand.erase(P2Hand.begin() + randomVictim);
			}
			if (P2Hand.empty()) {
				m_players[0].addGold(3);
				m_players[1].setHP(m_players[1].getHP() - calculateHpLost(P1Hand));
				break;
			}

			std::cout << "Player : 2 attacks " << P1Hand[randomOponent].getName() << " and deals " << P2Hand[randomVictim].getAttackDmg() << " Damages" << std::endl;

			P1Hand[randomOponent].setHealth(P1Hand[randomOponent].getHealth() - P2Hand[randomVictim].getAttackDmg());

			Sleep(1000);

			if (P1Hand[randomOponent].getHealth() <= 0) {
				P1Hand.erase(P1Hand.begin() + randomOponent);
			}
			if (P1Hand.empty()) {
				m_players[1].addGold(3);
				m_players[0].setHP(m_players[0].getHP() - calculateHpLost(P2Hand));
				break;
			}
		}
	}
	if (p1 < p2) {

		while ((P1Hand.empty() == false) && (P2Hand.empty() == false)) {
			int randomOponent = rand() % P2Hand.size();
			int randomVictim = rand() % P1Hand.size();

			std::cout << "Player : 2 attacks " << P1Hand[randomOponent].getName() << " and deals " << P2Hand[randomVictim].getAttackDmg() << " Damages" << std::endl;

			P1Hand[randomVictim].setHealth(P1Hand[randomVictim].getHealth() - P2Hand[randomOponent].getAttackDmg());

			Sleep(1000);

			if (P1Hand[randomVictim].getHealth() <= 0) {
				P1Hand.erase(P1Hand.begin() + randomVictim);
			}
			if (P1Hand.empty()) {
				m_players[1].addGold(3);
				m_players[0].setHP(m_players[0].getHP() - calculateHpLost(P2Hand));
				break;
			}

			P2Hand[randomOponent].setHealth(P2Hand[randomOponent].getHealth() - P1Hand[randomVictim].getAttackDmg());

			std::cout << "Player : 1 attacks " << P2Hand[randomVictim].getName() << " and deals " << P1Hand[randomOponent].getAttackDmg() << " Damages" << std::endl;

			Sleep(1000);

			if (P2Hand[randomOponent].getHealth() <= 0) {
				P2Hand.erase(P2Hand.begin() + randomOponent);
			}
			if (P2Hand.empty()) {
				m_players[0].addGold(3);
				m_players[1].setHP(m_players[1].getHP() - calculateHpLost(P1Hand));
				break;
			}
		}
	}
}

int Game::calculateHpLost(std::vector<Battler> playerBattler) {
	int totalHp = 0;
	for (int i = 0; i < playerBattler.size(); i++) {
		totalHp += playerBattler[i].getHealth();
	}

	return totalHp;
}

void Game::checkTier() {
	if (m_players[indexCurrentPlayer].getTavernTier() == 1) {
		m_battlerList.clear();
		// Tier 1
		m_battlerList.push_back(Battler("Goblin Grunt", 2, 5, 1, "Demon"));
		m_battlerList.push_back(Battler("Murloc Scout", 1, 1, 1, "Murloc"));
		m_battlerList.push_back(Battler("Young Wolf", 1, 1, 1, "Beast"));
		m_battlerList.push_back(Battler("Clockwork Gnome", 1, 2, 1, "Mech"));

		refreshBattlerList();
	}
	if (m_players[indexCurrentPlayer].getTavernTier() == 2) {
		m_battlerList.clear();
		// Tier 1
		m_battlerList.push_back(Battler("Goblin Grunt", 2, 5, 1, "Demon"));
		m_battlerList.push_back(Battler("Murloc Scout", 1, 1, 1, "Murloc"));
		m_battlerList.push_back(Battler("Young Wolf", 1, 1, 1, "Beast"));
		m_battlerList.push_back(Battler("Clockwork Gnome", 1, 2, 1, "Mech"));
		// Tier 2
		m_battlerList.push_back(Battler("Imp", 3, 5, 2, "Demon"));
		m_battlerList.push_back(Battler("Murloc Tidehunter", 2, 2, 2, "Murloc"));
		m_battlerList.push_back(Battler("Dire Wolf", 2, 2, 2, "Beast"));
		m_battlerList.push_back(Battler("Mechanical Dragonling", 3, 3, 2, "Mech"));

		refreshBattlerList();
	}
	if (m_players[indexCurrentPlayer].getTavernTier() == 3) {
		m_battlerList.clear();
		// Tier 1
		m_battlerList.push_back(Battler("Goblin Grunt", 2, 5, 1, "Demon"));
		m_battlerList.push_back(Battler("Murloc Scout", 1, 1, 1, "Murloc"));
		m_battlerList.push_back(Battler("Young Wolf", 1, 1, 1, "Beast"));
		m_battlerList.push_back(Battler("Clockwork Gnome", 1, 2, 1, "Mech"));
		// Tier 2
		m_battlerList.push_back(Battler("Imp", 3, 5, 2, "Demon"));
		m_battlerList.push_back(Battler("Murloc Tidehunter", 2, 2, 2, "Murloc"));
		m_battlerList.push_back(Battler("Dire Wolf", 2, 2, 2, "Beast"));
		m_battlerList.push_back(Battler("Mechanical Dragonling", 3, 3, 2, "Mech"));
		// Tier 3
		m_battlerList.push_back(Battler("Voidwalker", 4, 5, 3, "Demon"));
		m_battlerList.push_back(Battler("Murloc Warleader", 3, 3, 3, "Murloc"));
		m_battlerList.push_back(Battler("Savannah Highmane", 4, 4, 3, "Beast"));
		m_battlerList.push_back(Battler("Annoy-o-Tron", 2, 4, 3, "Mech"));

		refreshBattlerList();
	}
	if (m_players[indexCurrentPlayer].getTavernTier() == 4) {
		m_battlerList.clear();
		// Tier 1
		m_battlerList.push_back(Battler("Goblin Grunt", 2, 5, 1, "Demon"));
		m_battlerList.push_back(Battler("Murloc Scout", 1, 1, 1, "Murloc"));
		m_battlerList.push_back(Battler("Young Wolf", 1, 1, 1, "Beast"));
		m_battlerList.push_back(Battler("Clockwork Gnome", 1, 2, 1, "Mech"));
		// Tier 2
		m_battlerList.push_back(Battler("Imp", 3, 5, 2, "Demon"));
		m_battlerList.push_back(Battler("Murloc Tidehunter", 2, 2, 2, "Murloc"));
		m_battlerList.push_back(Battler("Dire Wolf", 2, 2, 2, "Beast"));
		m_battlerList.push_back(Battler("Mechanical Dragonling", 3, 3, 2, "Mech"));
		// Tier 3
		m_battlerList.push_back(Battler("Voidwalker", 4, 5, 3, "Demon"));
		m_battlerList.push_back(Battler("Murloc Warleader", 3, 3, 3, "Murloc"));
		m_battlerList.push_back(Battler("Savannah Highmane", 4, 4, 3, "Beast"));
		m_battlerList.push_back(Battler("Annoy-o-Tron", 2, 4, 3, "Mech"));
		// Tier 4
		m_battlerList.push_back(Battler("el famoso Diego de VILELA MONTEIRO", 666, 666, 4, "Demon"));
		m_battlerList.push_back(Battler("Murloc Tastyfish", 4, 4, 4, "Murloc"));
		m_battlerList.push_back(Battler("Giant Wolf", 5, 5, 4, "Beast"));
		m_battlerList.push_back(Battler("Mechano-Egg", 3, 5, 4, "Mech"));

		refreshBattlerList();
	}
}