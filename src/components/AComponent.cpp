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

void nts::AComponent::simulate(std::size_t tick)
{
    if (tick == _lastTick)
        return;
    _lastTick = tick;
    for (auto &pin: _pins)
        pin.second.simulate(tick);
}

nts::Tristate nts::AComponent::checkPin(const std::string &name, std::size_t pin)
{
    if (_pins.find(pin) == _pins.end())
        throw AComponent::Exception(name + ": Invalid pin");
    return _pins[pin].compute();
}
