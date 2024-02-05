/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** True
*/

#include "src/IComponent.hpp"

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw AComponent::Exception("TrueComponent: Invalid pin");
    return nts::True;
}
