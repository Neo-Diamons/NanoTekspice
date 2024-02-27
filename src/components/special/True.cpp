/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** True
*/

#include "Special.hpp"

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw AComponent::ExceptionInvalidPin("TrueComponent: Invalid pin");
    return nts::True;
}
