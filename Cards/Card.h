//
// Created by omarz on 13/06/2022.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H

#include <iostream>
#include <string>
#include <memory>
#include "Player.h"
#include "utilities.h"
using std::ostream;
using std::string;
using std::shared_ptr;

class Card {
public:
    /*
     * C'tor of Card class
     * @return
     *      A new instance of Card.
    */
    Card(string name);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual bool applyEncounter(shared_ptr<Player> player) const = 0;

    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual void printInfo(ostream& os) const;

    friend ostream& operator<<(ostream& os, const Card& card);

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    ~Card() = default;
    Card& operator=(const Card& other) = default;


protected:
    string m_name;

};


#endif //EX4_CARD_H
