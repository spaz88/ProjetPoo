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

	void diplayCard();

	std::string getName() { return this->name; };
	int getDamage() { return this->damage; };
	int getHealth() { return this->health; };
	int getPrice() { return this->price; };
};
