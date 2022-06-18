//
// Created by omarz on 13/06/2022.
//

#include "Merchant.h"

Merchant::Merchant(): Card("Merchant") {}
bool Merchant::applyEncounter(Player& player) const
{
    int toBuy;
    bool flag = true;
    int coins = 0;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    std::cin >> toBuy;
    if(toBuy != 0 && toBuy != 1 && toBuy != 2)
    {
        flag = false;
    }
    while(!flag)
    {
        printInvalidInput();
        std::cin >> toBuy;
        if(toBuy == 0 || toBuy == 1 || toBuy == 2)
        {
            flag = true;
        }
    }
    if(toBuy == 1)
    {
        if(player.getCoins() >= 5)
        {
            player.heal(1);
            player.pay(5);
            coins = 5;
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
        }
    }
    if(toBuy == 2)
    {
        if(player.getCoins() >= 10)
        {
            player.buff(1);
            player.pay(10);
            coins = 10;
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
        }
    }
    printMerchantSummary(std::cout, player.getName(), toBuy, coins);
}
