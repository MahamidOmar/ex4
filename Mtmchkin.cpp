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

std::shared_ptr<Card> getCardType(const std::string& name)
{
    if(name.compare("Barfight") == 0)
        return std::shared_ptr<Card>(new Barfight());
    if(name.compare("Dragon") == 0)
        return std::shared_ptr<Card>(new Dragon());
    if(name.compare("Fairy") == 0)
        return std::shared_ptr<Card>(new Fairy());
    if(name.compare("Goblin") == 0)
        return std::shared_ptr<Card>(new Goblin());
    if(name.compare("Merchant") == 0)
        return std::shared_ptr<Card>(new Merchant());
    if(name.compare("Pitfall") == 0)
        return std::shared_ptr<Card>(new Pitfall());
    if(name.compare("Treasure") == 0)
        return std::shared_ptr<Card>(new Treasure());
    if(name.compare("Vampire") == 0)
        return std::shared_ptr<Card>(new Vampire());

    return nullptr;
}
std::shared_ptr<Player> getPlayerType(const std::string& player_class, const std::string& name)
{
    if(player_class.compare("Fighter") == 0)
        return std::shared_ptr<Player>(new Fighter(name));
    if(player_class.compare("Wizard") == 0)
        return std::shared_ptr<Player>(new Wizard(name));
    if(player_class.compare("Rouge") == 0)
        return std::shared_ptr<Player>(new Rouge(name));
    return nullptr;
}

bool checkPlayerInvalid(const std::string& name)
{
    if(name.length() > 15 || name.length() == 0)
    {
        return false;
    }
    for(int i = 0 ; i < name.length() ; ++i)
    {
        char current = name[i];
        if(!((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z')))
        {
            return false;
        }
        return true;
    }
}
bool checkClassInvalid(const std::string& name)
{
    if(name.compare("Fighter") == 0 || name.compare("Rouge") == 0 || name.compare("Wizard") == 0)
    {
        return true;
    }
    return false;
}

void fillPlayersQueue(std::deque<std::shared_ptr<Player>>& players)
{
    int size;
    printStartGameMessage();
    printEnterTeamSizeMessage();
    std::cin >> size;
    while(size < 2 || size > 6)
    {
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        std::cin >> size;
    }
    for(int i = 0 ; i < size ; i++)
    {
        printInsertPlayerMessage();

        std::string current_player;
        std::cin >> current_player;
        int toSlice = current_player.find(" ");
        std::string player_name = current_player.substr(0, toSlice);
        std::string player_class = current_player.substr(toSlice + 1);
        bool flag = checkPlayerInvalid(player_name) && checkClassInvalid(player_class);
        while(!flag)
        {
            if(!checkPlayerInvalid(player_name))
            {
                printInvalidName();
                std::cin >> current_player;
                toSlice = current_player.find(" ");
                player_name = current_player.substr(0, toSlice);
                player_class = current_player.substr(toSlice + 1);
            }
            else
            {
                printInvalidClass();
                std::cin >> current_player;
                toSlice = current_player.find(" ");
                player_name = current_player.substr(0, toSlice);
                player_class = current_player.substr(toSlice + 1);
            }
            flag = checkPlayerInvalid(player_name) && checkClassInvalid(player_class);
        }
        players.push_back(std::shared_ptr<Player>(getPlayerType(player_class, player_name)));
    }
}

////end of help functions

Mtmchkin::Mtmchkin(const std::string fileName): m_rounds(0)
{
    std::ifstream file(fileName);
    if(!file)
    {
        ////throw exception DeckFileNotFound
    }
    std::string currentCard;
    int line = 1;
    while (std::getline(file, currentCard))
    {
        if(!checkCardInvalid(currentCard))
        {
            ////throw exception DeckFileFormatError(line)
        }
        this->m_cards.push_back(std::shared_ptr<Card>(getCardType(currentCard)));
        ++line;
    }
    if(line < 6)
    {
        ////throw exception DeckFileInvalidSize
    }
    fillPlayersQueue(this->m_players);
}

void Mtmchkin::playRound()
{}

void Mtmchkin::printLeaderBoard() const
{}

bool Mtmchkin::isGameOver() const
{}

int Mtmchkin::getNumberOfRounds() const
{}

