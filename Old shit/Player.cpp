#include "Player.h"

Player::Player()
{
	Player::name = "";
	Player::health = 0;
	Player::gold = 0;
	Player::level = 0;
}

Player::Player(std::string name, int health, int gold, int level)
{
	this->name = name;
	this->health = health;
	this->gold = gold;
	this->level = level;
}

int Player::getGold()
{
	return this->gold;
}
int Player::getHealth()
{
	return this->health;
}
int Player::getLevel()
{
	return this->level;
}

void Player::setGold(int newGold)
{
	this->gold = newGold;
}
void Player::setHealth(int newHealth)
{
	this->health = newHealth;
}
void Player::setLevel(int newLevel)
{
	this->level = +newLevel;
}

void Player::diplayStats()
{
	std::cout << "Player : " << this->name << "		Gold : " << this->gold << "			Level : " << this->level << std::endl;
}