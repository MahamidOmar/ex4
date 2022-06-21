//
// Created by omarz on 13/06/2022.
//

#include "Merchant.h"

Merchant::Merchant(): Card("Merchant") {}
//bool Merchant::applyEncounter(Player& player) const
//{
////    int toBuy;
//    std::string toBuy;
//    bool flag = true;
//    int coins = 0;
//    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
//    std::cin >> toBuy;
//    if(toBuy.compare("0") != 0 && toBuy.compare("1") != 0 && toBuy.compare("2") != 0)
//    {
//        flag = false;
//    }
//    while(!flag)
//    {
//        printInvalidInput();
//        std::cin >> toBuy;
//        if(toBuy.compare("0") != 0 || toBuy.compare("1") != 0 || toBuy.compare("2") != 0)
//        {
//            flag = true;
//        }
//    }
//    if(toBuy.compare("1") == 0)
//    {
//        if(player.getCoins() >= 5)
//        {
//            player.heal(1);
//            player.pay(5);
//            coins = 5;
//        }
//        else
//        {
//            printMerchantInsufficientCoins(std::cout);
//        }
//    }
//    if(toBuy.compare("2") == 0)
//    {
//        if(player.getCoins() >= 10)
//        {
//            player.buff(1);
//            player.pay(10);
//            coins = 10;
//        }
//        else
//        {
//            printMerchantInsufficientCoins(std::cout);
//        }
//    }
//    int tmp = std::stoi(toBuy);
//    printMerchantSummary(std::cout, player.getName(), tmp, coins);
//    return true;
//}

bool Merchant::applyEncounter(Player& player) const
{
//    int toBuy;
    std::string toBuy;
    bool flag = true;
    int coins = 0;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    std::getline(std::cin, toBuy);
    int tmp = std::stoi(toBuy);
    if(tmp != 0 && tmp != 1 && tmp != 2)
    {
        flag = false;
    }
    while(!flag)
    {
        printInvalidInput();
        std::cin >> toBuy;
        if(tmp == 0 || tmp == 1 || tmp == 2)
        {
            flag = true;
        }
    }
    if(tmp == 1)
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
    if(tmp == 2)
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
    printMerchantSummary(std::cout, player.getName(), tmp, coins);
    return true;
}
