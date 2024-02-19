/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** AComponent
*/

#include "src/IComponent.hpp"

#include <utility>

nts::AComponent::Exception::Exception(std::string message)
    : _message(std::move(message))
{}

const char *nts::AComponent::Exception::what() const noexcept
{
    return _message.c_str();
}

void nts::AComponent::setLink(std::size_t pin, std::shared_ptr<IComponent> other, std::size_t otherPin)
{
    _pins[pin] = Link(other, otherPin);
}
