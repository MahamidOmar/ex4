#include <iostream>
#include "Player.h"

Player::Player(string name):
        m_name(name), m_level(BasicLevel), m_force(BasicForce) , m_coins(BasicCoins)
{}

void Player::levelUp()
{
    if(m_level == MaxLevel)
    {
        return;
    }
    m_level++;
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int toBuff)
{
    if(toBuff <= 0)
    {
        return;
    }
    m_force += toBuff;
}

void Player::heal(int hp)
{
    if(hp <= 0)
    {
        return;
    }
    m_HP += hp;
}

void Player::damage(int damage)
{
    if(damage <= 0)
    {
        return;
    }
    m_HP -= damage;
}


////maybe add || m_level == 10
bool Player::isKnockedOut() const
{
    return m_HP == 0 || m_level == MaxLevel;
}

void Player::addCoins(int coins)
{
    if(coins < 0)
    {
        return;
    }
    m_coins += coins;
}

bool Player::pay(int coins)
{
    if(coins < 0)
    {
        return true;
    }
    if(coins > m_coins)
    {
        return false;
    }
    m_coins -= coins;
    return true;
}

int Player::getAttackStrength()const
{
    return m_level + m_force;
}

ostream& operator<<(ostream& os, const Player& player)
{
    player.printPlayerInfo(os);
    return os;
}


