#include "Player.h"

Player::Player(std::string name, int health, int gold, int level, std::vector<Battlers> playerBattlers) {
	this->name = name;
	this->health = health;
	this->gold = gold;
	this->level = level;
	this->playerBattlers = playerBattlers;
}

int Player::getGold() {
	return this->gold;
}
int Player::getHealth() {
	return this->health;
}
int Player::getLevel() {
	return this->level;
}
std::vector<Battlers> Player::getPlayerBattlers() {
	return this->playerBattlers;
}

void Player::setGold(int newGold) {
	this->gold = newGold;
}
void Player::setHealth(int newHealth) {
	this->health = newHealth;
}
void Player::setLevel(int newLevel) {
	this->level = newLevel;
}
void Player::setPlayerBattlers(std::vector<Battlers> newPlayerBattlers) {
	this->playerBattlers = newPlayerBattlers;
}
