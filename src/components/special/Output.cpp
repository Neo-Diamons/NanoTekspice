/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Output
*/

#include "Special.hpp"

void nts::OutputComponent::simulate([[maybe_unused]] std::size_t tick)
{}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw AComponent::Exception("OutputComponent: Invalid pin");
    return _pins[pin].compute();
}
