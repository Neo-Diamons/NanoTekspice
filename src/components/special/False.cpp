/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** False
*/

#include "src/IComponent.hpp"

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw AComponent::Exception("FalseComponent: Invalid pin");
    return nts::False;
}
