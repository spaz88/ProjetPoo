#include "Battler.h"

Battler::Battler(const std::string& name, int attackDmg, int health, int tier, const std::string& tribe)
{
	this->m_name = name;
	this->m_attackDmg = attackDmg;
	this->m_health = health;
	this->m_tier = tier;
	this->m_tribe = tribe;
}

const std::string& Battler::getName() const
{
	return m_name;
}

int Battler::getAttackDmg() const
{
	return m_attackDmg;
}

int Battler::getHealth() const
{
	return m_health;
}

int Battler::getTier() const
{
	return m_tier;
}

const std::string& Battler::getTribe() const
{
	return m_tribe;
}

void Battler::setAttackDmg(int attackDmg)
{
	m_attackDmg = attackDmg;
}

void Battler::setHealth(int health)
{
	m_health = health;
}

void Battler::setTier(int tier)
{
	m_tier = tier;
}

void Battler::setTribe(const std::string& tribe)
{
	m_tribe = tribe;
}

