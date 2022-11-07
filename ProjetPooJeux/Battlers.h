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
};

