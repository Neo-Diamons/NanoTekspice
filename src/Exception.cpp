/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Exception
*/

#include "Exception.hpp"

using namespace nts;

[[nodiscard]] const char *Exception::what() const noexcept
{
    return this->_message.c_str();
}

[[nodiscard]] std::string Exception::makeMessage() const
{
    return "nts::Exception: An error has occured";
}
