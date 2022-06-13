//
// Created by omarz on 13/06/2022.
//

#include "Card.h"

Card::Card(string name): m_name(name)
{}

void Card::printInfo(ostream& os) const
{
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

ostream& operator<<(ostream& os, const Card& card)
{
    card.printInfo(os);
    return os;
}



