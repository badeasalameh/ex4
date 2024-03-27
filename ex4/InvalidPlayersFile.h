//
// Created by user on 3/27/2024.
//

#ifndef EX4_INVALIDPLAYERSFILE_H
#define EX4_INVALIDPLAYERSFILE_H
#include <iostream>

     class InvalidPlayersFile : public std::exception {
     private:
         std::string m_errorMessage;

     public:
         explicit InvalidPlayersFile() : m_errorMessage("Invalid Players File") {}

         const char *what() const noexcept override {
             return m_errorMessage.c_str();
         }
     };

#endif //EX4_INVALIDPLAYERSFILE_H
