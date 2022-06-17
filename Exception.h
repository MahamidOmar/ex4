//
// Created by omarz on 13/06/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

class DeckFileNotFound : public std::exception
{
public:
    const char* what() const noexcept override;
};

class DeckFileFormatError : public std::exception
{
private:
    int m_line;
public:
    DeckFileFormatError(int line);
    const char* what() const noexcept override;
};

class DeckFileInvalidSize : public std::exception
{
public:
    const char* what() const noexcept override;
};


////implementations
const char* DeckFileNotFound::what() const noexcept
{
    return "Deck File Error: File not found";
}

DeckFileFormatError::DeckFileFormatError(int line) : m_line(line)
{}
const char* DeckFileFormatError::what() const noexcept
{
    std::string message = "Deck File Error: File format error in line ";
    message += std::to_string(m_line);
    return message.c_str();
}

const char* DeckFileInvalidSize::what() const noexcept
{
    return "Deck File Error: Deck size is invalid";
}



#endif //EX4_EXCEPTION_H
