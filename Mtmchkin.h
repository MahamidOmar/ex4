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

#include "Cards/Card.h"
#include "Cards/Battle.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"

#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "Players/Rouge.h"

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
//    std::deque<std::unique_ptr<Player>>::const_iterator getFirstPosition() const;
//    std::deque<std::unique_ptr<Player>>::const_iterator getLastPosition() const;
//    std::deque<std::shared_ptr<Player>>::const_iterator getFirstPosition() const;
//    std::deque<std::shared_ptr<Player>>::const_iterator getLastPosition() const;

//    std::deque<std::shared_ptr<Player>> m_players;
    std::deque<std::unique_ptr<Player>> m_players;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;


    std::deque<std::unique_ptr<Card>> m_cards;

    int m_numOfPlayers;
    int m_rounds;

//    std::deque<std::shared_ptr<Card>> m_cards;

//    std::deque<std::unique_ptr<Player>>::iterator m_currentPlayer;
//    std::deque<std::shared_ptr<Player>>::iterator m_currentPlayer;
//    std::deque<std::shared_ptr<Card>>::iterator m_currentCard;
//    std::deque<std::unique_ptr<Card>>::iterator m_currentCard;


//    int m_toAddFirst;
//    int m_toAddLast;
};



#endif /* MTMCHKIN_H_ */
