#pragma once
#include <string>
#include "Battler.h"


class Ability
{
public:
	Ability(const std::string& name, const std::string& description, const std::string& type);


	const std::string& getName() const;
	const std::string& getDescription() const;
	const std::string& getType() const;
	void setEffect(Battler& source, Battler& target, std::string type);
private:
	std::string m_name;
	std::string m_description;
	std::string m_type;
};

