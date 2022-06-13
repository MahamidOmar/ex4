
#include "Wizard.h"

Wizard::Wizard(string name): Player(name)
{}

void Wizard::heal(int hp)
{
    this->Player::heal(2 * hp);
}


