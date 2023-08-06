/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** error
*/

#include "../include/error.hpp"

error::error(const std::string &message)
{
    this->_message = message;
}

const char *error::what() const noexcept
{
    return this->_message.c_str();
}

error::~error()
{

}
