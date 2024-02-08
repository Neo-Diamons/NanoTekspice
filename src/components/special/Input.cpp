/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Input
*/

#include "src/IComponent.hpp"

void nts::InputComponent::simulate(std::size_t tick)
{
    if (_pins.find(0) != _pins.end()) {
        _pins[0].simulate(tick);
        return;
    }
    if (tick <= _lastTick)
        return;
    _lastTick = tick;
    _oldState = _state;
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw AComponent::Exception("InputComponent: Invalid pin");
    if (_pins.find(0) == _pins.end())
        return _oldState;
    return _pins[0].compute();
}

void nts::InputComponent::setState(nts::Tristate state)
{
    _state = state;
}
