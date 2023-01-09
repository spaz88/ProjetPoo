#pragma once
#include <string>
#include "Battler.h"

class Player
{
public:
    Player(const std::string& name, int gold, int tavernTier, int hp);

    const std::string& getName() const;
    int getGold() const;
    int getTavernTier() const;
    int getHP() const;
    std::vector<Battler>& getBattlers();
    std::vector<Battler>& getHand();

    void setGold(int gold);
    void setTavernTier(int tier);
    void setHP(int hp);
    void addBattler(const Battler& battler);
    void addToHand(const Battler& battler);
    void addGold(int amount);
    void removeFromHand(const Battler& battler);
    void refreshHand();

private:
    std::string m_name;
    int m_gold;
    int m_tavernTier;
    int m_hp;
    std::vector<Battler> m_battlers;
    std::vector<Battler> m_hand;
};