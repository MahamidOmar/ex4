//
// Created by omarz on 13/06/2022.
//

#ifndef EX4_ROUGE_H
#define EX4_ROUGE_H
#include "Player.h"
#include <string>

class Rouge : public Player{
public:
    Rouge(const string& name);
    void addCoins(int coins) override;
    void printPlayerInfo(ostream& os) const override;
    std::unique_ptr<Player> clone() const override;
};


#endif //EX4_ROUGE_H
