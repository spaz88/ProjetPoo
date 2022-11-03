#include "Battlers.h"
#include <iostream>

Battlers::Battlers(std::string name, int damage, int health, int price) {
	this->name = name;
	this->damage = damage;
	this->health = health;
	this->price = price;
}

void Battlers::diplayCard() {
	std::cout << "**********" << std::endl;
	std::cout << "*"<< this->name <<"*" << std::endl;
	std::cout << "*"<< this->damage <<"*" << std::endl;
	std::cout << "*"<<this->health<<"*" << std::endl;
	std::cout << "**********" << std::endl;

}