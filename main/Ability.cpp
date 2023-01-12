#include "Ability.h"

Ability::Ability(const std::string& name, const std::string& description, const std::string& type)
{
	this->m_name = name;
	this->m_description = description;
	this->m_type = type;
}

const std::string& Ability::getName() const
{
	return m_name;
}

const std::string& Ability::getDescription() const
{
	return m_description;
}

const std::string& Ability::getType() const
{
	return m_type;
}

void Ability::setEffect(Battler& target, std::string tribe)
{
	if (tribe == "Demon") {
		target.setAttackDmg(target.getAttackDmg() + 1);
	}
	if (tribe == "Murloc") {
		target.setAttackDmg(target.getAttackDmg() - 1);
	}
	if (tribe == "Beast") {
		target.setAttackDmg(target.getAttackDmg() + 2);
	}
	if (tribe == "Mech") {
		target.setAttackDmg(target.getAttackDmg() - 2);
	}
}
