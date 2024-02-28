/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** False
*/

#include "Special.hpp"

#include "src/parser/Exception.hpp"

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw ExceptionInvalidPin("FalseComponent: Invalid pin");
    return nts::False;
}
