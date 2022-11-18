#include "Battlers.h"
#include <iostream>

Battlers::Battlers(std::string name, int damage, int health, int price) {
	this->name = name;
	this->damage = damage;
	this->health = health;
	this->price = price;
}

void Battlers::diplayCard() {
	std::cout << "+--------------+" << std::endl;
	std::cout << "|"<<"Name : " << this->name << "|" << std::endl;
	std::cout << "|"<<"Damage : " << this->damage << "|" << std::endl;
	std::cout << "|"<<"Health : " << this->health << "|" << std::endl;
	std::cout << "|"<<"Price : " << this->price << "|" << std::endl;
	std::cout << "+--------------+" << std::endl<<std::endl;

}