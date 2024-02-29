/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Clock
*/

#include "Special.hpp"

#include "src/parser/Exception.hpp"

void nts::ClockComponent::simulate(const std::size_t tick)
{
    if (tick == _lastTick)
        return;
    _lastTick = tick;
    _oldState = _state;
    _state = !_state;
}

nts::Tristate nts::ClockComponent::compute(const std::size_t pin)
{
    if (pin != 1)
        throw ExceptionInvalidPin("Clock: Invalid pin");
    return _oldState;
}

void nts::ClockComponent::setState(const Tristate state)
{
    _state = state;
}
