/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Input
*/

#include "Special.hpp"

void nts::InputComponent::simulate(std::size_t tick)
{
    if (tick == _lastTick)
        return;
    _lastTick = tick;
    if (_pins.find(1) != _pins.end()) {
        _pins[1].simulate(tick);
        return;
    }
    _oldState = _state;
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw AComponent::ExceptionInvalidPin("InputComponent: Invalid pin");
    if (_pins.find(1) == _pins.end())
        return _oldState;
    return _pins[1].compute();
}

void nts::InputComponent::setState(nts::Tristate state)
{
    _state = state;
}
