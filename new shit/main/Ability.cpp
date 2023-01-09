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

void Ability::setEffect(Battler& source, Battler& target, std::string tribe)
{
	/*if (type == "poison")
	{
		target.setHealth(target.getHealth() - 2);
	}*/
}
