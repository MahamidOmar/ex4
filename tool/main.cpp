//
// Created by omarz on 23/06/2022.
//

#include "../Mtmchkin.h"

int main()
{
    try{
        Mtmchkin game("deck.txt");
        while(!game.isGameOver())
        {
            game.playRound();
        }
        game.printLeaderBoard();
    } catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 0;
    }
    return 1;
}
