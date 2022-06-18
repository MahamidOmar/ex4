#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <memory>
#include <iostream>
#include <queue>
#include <deque>
#include <map>
#include <string>
#include <fstream>

#include "Exception.h"

#include "Card.h"
#include "Battle.h"
#include "Barfight.h"
#include "Dragon.h"
#include "Fairy.h"
#include "Goblin.h"
#include "Merchant.h"
#include "Pitfall.h"
#include "Treasure.h"
#include "Vampire.h"

#include "Player.h"
#include "Fighter.h"
#include "Wizard.h"
#include "Rouge.h"

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    std::deque<std::shared_ptr<Player>>::const_iterator getFirstPosition() const;
    std::deque<std::shared_ptr<Player>>::const_iterator getLastPosition() const;

    std::deque<std::shared_ptr<Player>> m_players;
    std::deque<std::shared_ptr<Card>> m_cards;
//    std::map<int, std::shared_ptr<Player>> m_knockedPlayers;

    std::deque<std::shared_ptr<Player>>::iterator m_currentPlayer;
    std::deque<std::shared_ptr<Card>>::iterator m_currentCard;

    int m_numOfPlayers;
    int m_rounds;
//    int* m_rankings;
    int m_toAddFirst;
    int m_toAddLast;
};



#endif /* MTMCHKIN_H_ */
