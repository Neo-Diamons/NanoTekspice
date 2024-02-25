/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Link
*/

#include <sstream>

#include "Link.hpp"

using namespace nts;

[[nodiscard]] Tristate Link::compute() const
{
    return _component->compute(this->_pin);
}

[[nodiscard]] std::string Link::InvalidPinException::makeMessage() const
{
    std::stringstream message;

    message << "Link::InvalidPinException: Pin " << this->_pin
        << " on component '" << this->_component->getName()
        << "' is not a valid " << (this->_isOutputPin ? "output pin." : "input pin.");

    return message.str();
}

[[nodiscard]] const char *Link::InvalidPinException::what() const noexcept
{
    return this->_message.c_str();
}