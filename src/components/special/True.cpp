/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** True
*/

#include "Special.hpp"

#include "src/parser/Exception.hpp"

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw ExceptionInvalidPin("TrueComponent: Invalid pin");
    return nts::True;
}
