//
// Created by omarz on 13/06/2022.
//

#include "Mtmchkin.h"

////start help functions
bool checkCardInvalid(const std::string& name)
{
    if(name.compare("Barfight") == 0 || name.compare("Dragon") == 0 || name.compare("Fairy") == 0)
    {
        return true;
    }
    else
    {
        if(name.compare("Goblin") == 0 || name.compare("Merchant") == 0 || name.compare("Pitfall") == 0)
        {
            return true;
        }
        else
        {
            if(name.compare("Vampire") == 0 || name.compare("Treasure") == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

std::unique_ptr<Card> getCardType(const std::string& name)
{
    if(name.compare("Barfight") == 0)
        return std::unique_ptr<Card>(new Barfight());
    if(name.compare("Dragon") == 0)
        return std::unique_ptr<Card>(new Dragon());
    if(name.compare("Fairy") == 0)
        return std::unique_ptr<Card>(new Fairy());
    if(name.compare("Goblin") == 0)
        return std::unique_ptr<Card>(new Goblin());
    if(name.compare("Merchant") == 0)
        return std::unique_ptr<Card>(new Merchant());
    if(name.compare("Pitfall") == 0)
        return std::unique_ptr<Card>(new Pitfall());
    if(name.compare("Treasure") == 0)
        return std::unique_ptr<Card>(new Treasure());
    if(name.compare("Vampire") == 0)
        return std::unique_ptr<Card>(new Vampire());

    return nullptr;
}
std::unique_ptr<Player> getPlayerType(const std::string& player_class, const std::string& name)
{
    if(player_class.compare("Fighter") == 0)
        return std::unique_ptr<Player>(new Fighter(name));
    if(player_class.compare("Wizard") == 0)
        return std::unique_ptr<Player>(new Wizard(name));
    if(player_class.compare("Rouge") == 0)
        return std::unique_ptr<Player>(new Rouge(name));
    return nullptr;
}

bool checkPlayerInvalid(const std::string& name)
{
    if(name.length() > 15 || name.length() == 0)
    {
        return false;
    }
    for(int i = 0 ; i < (int)name.length() ; ++i)
    {
        char current = name[i];
        if(!((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z')))
        {
            return false;
        }
    }
    return true;
}
bool checkClassInvalid(const std::string& name)
{
    if(name.compare("Fighter") == 0 || name.compare("Rouge") == 0 || name.compare("Wizard") == 0)
    {
        return true;
    }
    return false;
}

//void cutStrings(std::string& player, int toSlice ,std::string& player_name, std::string& player_class)
//{
//    player_name = player.substr(0, toSlice);
//    player_class = player.substr(toSlice + 1);
//}

void readSize(int& size)
{
    std::cin >> size;
    while(size < 2 || size > 6)
    {
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        std::cin >> size;
    }
}

int fillPlayersDeque(std::deque<std::unique_ptr<Player>>& players)
{
    int size;
    printStartGameMessage();
    printEnterTeamSizeMessage();
    readSize(size);
    for(int i = 0 ; i < size ; i++)
    {
        printInsertPlayerMessage();

//        std::string current_player;
//        std::cin >> current_player;
//        int toSlice = current_player.find(" ");
        std::string player_name;
        std::cin >> player_name;

        std::string player_class;
        std::cin >> player_class;
//        cutStrings(current_player, toSlice, player_name, player_class);
        bool flag = checkPlayerInvalid(player_name) && checkClassInvalid(player_class);
        while(!flag)
        {
            if(!checkPlayerInvalid(player_name))
            {
                printInvalidName();
                std::cin >> player_name;
                std::cin >> player_class;
//                std::cin >> current_player;
//                toSlice = current_player.find(" ");
//                cutStrings(current_player, toSlice, player_name, player_class);
            }
            else
            {
                printInvalidClass();
                std::cin >> player_name;
                std::cin >> player_class;
//                std::cin >> current_player;
//                toSlice = current_player.find(" ");
//                cutStrings(current_player, toSlice, player_name, player_class);
            }
            flag = checkPlayerInvalid(player_name) && checkClassInvalid(player_class);
        }
        players.push_back(std::unique_ptr<Player>(getPlayerType(player_class, player_name)));
    }
    return size;
}

////end of help functions

Mtmchkin::Mtmchkin(const std::string fileName):  m_numOfPlayers(0), m_rounds(0)
{
    std::ifstream file(fileName);
    if(!file)
    {
        throw  DeckFileNotFound();
    }
    std::string currentCard;
    int line = 1;
    while (std::getline(file, currentCard))
    {
        if(!checkCardInvalid(currentCard))
        {
            throw  DeckFileFormatError(line);
        }
        this->m_cards.push_back(std::unique_ptr<Card>(getCardType(currentCard)));
        ++line;
    }
    if(line < 6)
    {
        throw  DeckFileInvalidSize();
    }
    m_numOfPlayers = fillPlayersDeque(this->m_players);
}

//std::deque<std::unique_ptr<Player>>::const_iterator Mtmchkin::getFirstPosition() const
//{
//    std::deque<std::unique_ptr<Player>>::const_iterator position = this->m_players.begin();
//    for(int i = 1 ; i < m_toAddFirst ; ++i)
//    {
//        ++position;
//    }
//    return position;
//}
//
//std::deque<std::unique_ptr<Player>>::const_iterator Mtmchkin::getLastPosition() const
//{
//    std::deque<std::unique_ptr<Player>>::const_iterator position = this->m_players.end();
//    for(int i = 1 ; i <= m_toAddLast ; ++i)
//    {
//        --position;
//    }
//    return position;
//}

void Mtmchkin::playRound()
{
    int current_players = m_players.size();

    for(int i = current_players ; i > 0 ; --i)
    {
        m_cards.front()->applyEncounter(*m_players.front());
        if(m_players.front()->isWinner())
        {
            ////add to winners
            m_winners.push_back(std::move(m_players.front()));
            m_players.pop_front();
        }else if(m_players.front()->isKnockedOut())
        {
            ////add to losers
            m_losers.push_back(std::move(m_players.front()));
            m_players.pop_front();
        }else
        {
            ////pop and pushback
            m_players.push_back(std::move(m_players.front()));
            m_players.pop_front();
        }
        m_cards.push_back(std::move(m_cards.front()));
        m_cards.pop_front();
    }
    if(isGameOver())
    {
        printLeaderBoard();
    }
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int rank = 1;
    for(std::deque<std::unique_ptr<Player>>::const_iterator it = m_winners.begin() ; it != m_winners.end() ; ++it)
    {
        printPlayerLeaderBoard(rank++, *(*it));
    }
    for(std::deque<std::unique_ptr<Player>>::const_iterator it = m_players.begin() ; it != m_players.end() ; ++it)
    {
        printPlayerLeaderBoard(rank++, *(*it));
    }
    for(std::deque<std::unique_ptr<Player>>::const_iterator it = m_losers.begin() ; it != m_losers.end() ; ++it)
    {
        printPlayerLeaderBoard(rank++, *(*it));
    }
}

bool Mtmchkin::isGameOver() const
{
//    for(std::deque<std::unique_ptr<Player>>::const_iterator it = m_players.begin(); it != m_players.end(); ++it)
//    {
//        if(!(*it)->isKnockedOut())
//        {
//            return false;
//        }
//    }
    if(!m_players.empty())
    {
        return false;
    }
    printGameEndMessage();
    return true;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_rounds + 1;
}

