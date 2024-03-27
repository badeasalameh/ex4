//
// Created by user on 3/27/2024.
//

#ifndef EX4_INVALIDCARDSFILE_H
#define EX4_INVALIDCARDSFILE_H
#include <iostream>

class InvalidCardsFile : public std::exception{
private:
    std::string m_errorMessage;

public:
    explicit InvalidCardsFile() : m_errorMessage("Invalid Cards File") {}

    const char* what() const noexcept override {
        return m_errorMessage.c_str();
    }
};



#endif //EX4_INVALIDCARDSFILE_H
