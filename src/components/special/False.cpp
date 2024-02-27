/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** False
*/

#include "Special.hpp"

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw AComponent::ExceptionInvalidPin("FalseComponent: Invalid pin");
    return nts::False;
}
