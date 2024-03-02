/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Input
*/

#include "Special.hpp"

#include "src/parsing/Exception.hpp"

void nts::InputComponent::simulate(const std::size_t tick)
{
    if (tick == _lastTick)
        return;
    _lastTick = tick;
    _oldState = _state;
}

nts::Tristate nts::InputComponent::compute(const std::size_t pin)
{
    if (pin != 1)
        throw ExceptionInvalidPin("Input: Invalid pin");
    return _oldState;
}

void nts::InputComponent::setState(const Tristate state)
{
    _state = state;
}
