/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Clock
*/

#include "Special.hpp"

#include "src/parser/Exception.hpp"

void nts::ClockComponent::simulate(std::size_t tick)
{
    if (_oldState == _state)
        _state = tick % 2 ? nts::False : nts::True;
    _oldState = _state;
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw ExceptionInvalidPin("ClockComponent: Invalid pin");
    return _oldState;
}

void nts::ClockComponent::setState(nts::Tristate state)
{
    _state = state;
}
