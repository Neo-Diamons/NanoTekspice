/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** LinkMap
*/

#include <sstream>

#include "LinkMap.hpp"

using namespace nts;

[[nodiscard]] std::string LinkMap::LinkNotFoundException::makeMessage() const noexcept
{
    std::stringstream message;

    message << "LinkMap::LinkNotFoundException: Pin " << this->_pin
        << " on component '" << this->_componentName
        << "' is not linked to any component";

    return message.str();
}

Tristate LinkMap::compute(std::size_t pin) const
{
    if (!this->contains(pin))
        throw LinkNotFoundException(pin, this->_component->getName());
    return this->at(pin).compute();
}

std::pair<LinkMap::iterator, bool> LinkMap::insert_or_assign(std::size_t pin, Link &&link)
{
    return this->std::map<std::size_t, Link>::insert_or_assign(pin, link);
}
