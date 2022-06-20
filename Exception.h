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
public:
    DeckFileFormatError(int line);
    ~DeckFileFormatError();
    const char* what() const noexcept override;
private:
    std::string* m_errorMessage;
    int m_line;
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
{
    m_errorMessage = new std::string ("Deck File Error: File format error in line ");
    *m_errorMessage += std::to_string(m_line);
}
const char* DeckFileFormatError::what() const noexcept
{
    return m_errorMessage->c_str();
}

DeckFileFormatError::~DeckFileFormatError()
{
    delete m_errorMessage;
}

const char* DeckFileInvalidSize::what() const noexcept
{
    return "Deck File Error: Deck size is invalid";
}



#endif //EX4_EXCEPTION_H
