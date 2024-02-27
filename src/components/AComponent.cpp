/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** AComponent
*/

#include "AComponent.hpp"

#include <utility>

nts::AComponent::ExceptionInvalidPin::ExceptionInvalidPin(std::string message)
    : _message(std::move(message))
{}

const char *nts::AComponent::ExceptionInvalidPin::what() const noexcept
{
    return _message.c_str();
}

bool nts::AComponent::asPin(std::size_t pin) const
{
    return pin > 0 || pin <= _nbPins;
}

nts::Tristate nts::AComponent::checkPin(const std::string &name, std::size_t pin)
{
    if (!asPin(pin))
        throw AComponent::ExceptionInvalidPin(name + ": Invalid pin");
    return _pins.find(pin) == _pins.end()
        ? nts::Undefined
        : _pins[pin].compute();
}

void nts::AComponent::setLink(std::size_t pin, std::shared_ptr<IComponent> other, std::size_t otherPin)
{
    if (!asPin(pin))
        throw AComponent::ExceptionInvalidPin("Invalid pin");
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
