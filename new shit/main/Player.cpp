#include "Player.h"

Player::Player(const std::string& name, int gold, int tavernTier, int hp)
{
    this->m_name = name;
    this->m_gold = gold;
    this->m_tavernTier = tavernTier;
    this->m_hp = hp;
}

const std::string& Player::getName() const
{
    return m_name;
}

int Player::getGold() const
{
    return m_gold;
}

int Player::getTavernTier() const
{
    return m_tavernTier;
}

int Player::getHP() const
{
    return m_hp;
}

std::vector<Battler>& Player::getBattlers()
{
    return m_battlers;
}

std::vector<Battler>& Player::getHand()
{
    return m_hand;
}

void Player::setGold(int gold)
{
    m_gold = gold;
}

void Player::setTavernTier(int tier)
{
    m_tavernTier = tier;
}

void Player::setHP(int hp)
{
    m_hp = hp;
}

void Player::addToHand(const Battler& battler)
{
    m_hand.push_back(battler);
}

void Player::addGold(int amount)
{
    m_gold += amount;
}

void Player::removeFromHand(const Battler& battler)
{
    auto it = std::find(m_hand.begin(), m_hand.end(), battler);
    if (it != m_hand.end())
        m_hand.erase(it);
}

void Player::refreshHand()
{
    // Clear the current hand
    m_hand.clear();

    // Fill the hand with new battlers from the available battler list
    for (int i = 0; i < 3; i++)
    {
        // Choose a random battler from the list of available battlers
        int index = std::rand() % m_battlers.size();
        Battler battler = m_battlers[index];

        // Add the battler to the player's hand
        m_hand.push_back(battler);

        // Remove the battler from the list of available battlers
        m_battlers.erase(m_battlers.begin() + index);
    }
}
