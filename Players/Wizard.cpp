
#include "Wizard.h"

Wizard::Wizard(string name): Player(name)
{}

void Wizard::heal(int hp)
{
    this->Player::heal(2 * hp);
}

void Wizard::printPlayerInfo(ostream& os) const
{
    printPlayerDetails(os, m_name, "Wizard", m_level, m_force, m_HP.getHP(), m_coins);
}
