/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "Link.hpp"

using namespace nts;

const std::string &AComponent::getName()
{
    return this->_name;
}

void AComponent::setLink(std::size_t pin, std::shared_ptr<IComponent> other, std::size_t otherPin)
{
    if (!this->getValidPins().first.contains(pin))
        throw Link::InvalidPinException(pin, this->getName());
    if (!other->getValidPins().second.contains(otherPin))
        throw Link::InvalidPinException(otherPin, other->getName(), true);
    _pins[pin] = Link(other, otherPin);
}
