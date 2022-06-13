//
// Created by omarz on 13/06/2022.
//

#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H


#include <iostream>
#include <cstring>
#include <string>
#include "utilities.h"
#include "HealthPoints.h"
using std::string;
using std::ostream ;

class Player
{
public:
    Player(string name);
    Player(const Player& player) = default;
    Player& operator=(const Player& player) = default;
    ~Player() = default;

//    void printInfo() const;


    int getLevel() const;

    void levelUp();

    virtual void buff(int toBuff);

    virtual void heal(int hp);

    virtual void damage(int damage);

    bool isKnockedOut() const;

    virtual void addCoins(int coins);

    bool pay(int coins);

    virtual int getAttackStrength()const;

    virtual void printPlayerInfo(ostream& os) const = 0;

    friend ostream& operator<<(ostream& os, const Player& player);

protected:

    string m_name;
    int m_level;
    int m_force;
    HealthPoints m_HP;
    int m_coins;

    static const int BasicLevel = 1;
    static const int BasicCoins = 10;
    static const int BasicForce = 5;
    static const int BasicHP = 100;
    static const int MaxLevel = 10;
};



#endif //EX4_PLAYER_H
