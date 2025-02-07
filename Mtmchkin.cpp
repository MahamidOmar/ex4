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
    if(player_class.compare("Rogue") == 0)
        return std::unique_ptr<Player>(new Rogue(name));
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
    if(name.compare("Fighter") == 0 || name.compare("Rogue") == 0 || name.compare("Wizard") == 0)
    {
        return true;
    }
    return false;
}

void readSize(int& size)
{
    std::string tmp_size;
    bool flag = true;
    while(flag)
    {
        std::getline(std::cin, tmp_size);
        try
        {
            size = std::stoi(tmp_size);
            if(size < 2 || size > 6)
            {
                printInvalidTeamSize();
                printEnterTeamSizeMessage();
                continue;
            }
            else
            {
                flag = false;
                break;
            }
        }catch (...)
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            continue;
        }
    }

//    std::cin >> size;
//    while(size < 2 || size > 6)
//    {
//        printInvalidTeamSize();
//        printEnterTeamSizeMessage();
//        std::cin >> size;
//    }
}

int fillPlayersDeque(std::deque<std::unique_ptr<Player>>& players)
{
    int size;
    printEnterTeamSizeMessage();
    readSize(size);
    for(int i = 0 ; i < size ; i++)
    {
        printInsertPlayerMessage();

        std::string player;
        std::getline(std::cin, player);

        std::string player_name;
        player_name = player.substr(0, player.find(" "));
//        std::cin >> player_name;

        std::string player_class;
        player_class = player.substr(player.find(" ") + 1, player.size());
//        std::cin >> player_class;
        bool flag = checkPlayerInvalid(player_name) && checkClassInvalid(player_class);
        while(!flag)
        {
            if(!checkPlayerInvalid(player_name))
            {
                printInvalidName();
                std::getline(std::cin, player);
                player_name = player.substr(0, player.find(" "));
                player_class = player.substr(player.find(" ") + 1, player.size());

//                std::cin >> player_name;
//                std::cin >> player_class;
            }
            else
            {
                printInvalidClass();
                std::getline(std::cin, player);
                player_name = player.substr(0, player.find(" "));
                player_class = player.substr(player.find(" ") + 1, player.size());

//                std::cin >> player_name;
//                std::cin >> player_class;
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
    printStartGameMessage();
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

void Mtmchkin::playRound()
{
    printRoundStartMessage(m_rounds + 1);
    int current_players = m_players.size();

    for(int i = current_players ; i > 0 ; --i)
    {
        printTurnStartMessage(m_players.front()->getName());
        m_cards.front()->applyEncounter(*m_players.front());
        if(m_players.front()->isWinner())
        {
            ////add to winners
            m_winners.push_back(std::move(m_players.front()));
            m_players.pop_front();
        }else if(m_players.front()->isKnockedOut())
        {
            ////add to losers
            m_losers.push_front(std::move(m_players.front()));
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
        printGameEndMessage();
//        printLeaderBoard();
    }
    ++m_rounds;
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
    if(!m_players.empty())
    {
        return false;
    }
    return true;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_rounds;
}

