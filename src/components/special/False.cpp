/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** False
*/

#include "Special.hpp"

#include "src/parsing/Exception.hpp"

nts::Tristate nts::FalseComponent::compute(const std::size_t pin)
{
    if (pin != 1)
        throw ExceptionInvalidPin("False: Invalid pin");
    return False;
}
