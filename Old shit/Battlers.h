#pragma once
#include <string>
class Battlers
{
private:
	std::string name;
	int damage;
	int health;
	int price;

public:
	Battlers(std::string name, int damage, int health, int price);
	Battlers();

	void displayCard();

	std::string getName() { return this->name; };
	// setter
	void setDamage(int damage) { this->damage = damage; };
	void setHealth(int health) { this->health = health; };
	// void setPrice(int price) { this->price = price; };
	// getter
	int getDamage() { return this->damage; };
	int getHealth() { return this->health; };
	int getPrice() { return this->price; };
};
