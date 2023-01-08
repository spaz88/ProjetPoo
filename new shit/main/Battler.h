#pragma once
#include <string>
#include <vector>


class Battler
{
public:
	Battler(const std::string& name, int attackDmg, int health, int tier, const std::string& tribe);

	const std::string& getName() const;
	int getAttackDmg() const;
	int getHealth() const;
	int getTier() const;
	const std::string& getTribe() const;

	void setAttackDmg(int attackDmg);
	void setHealth(int health);
	void setTier(int tier);
	void setTribe(const std::string& tribe);

	bool operator==(const Battler& battler) const {
		return (m_name == battler.m_name);
	}
private:
	std::string m_name;
	int m_attackDmg;
	int m_health;
	int m_tier;
	std::string m_tribe;
};


