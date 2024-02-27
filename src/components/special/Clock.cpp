/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Clock
*/

#include "Special.hpp"

void nts::ClockComponent::simulate(std::size_t tick)
{
    if (tick == 0)
        _state = nts::Undefined;
    else
        _state = tick % 2 ? nts::False : nts::True;
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw AComponent::Exception("ClockComponent: Invalid pin");
    return _state;
}

void nts::ClockComponent::setState(nts::Tristate state)
{
    _state = state;
}
