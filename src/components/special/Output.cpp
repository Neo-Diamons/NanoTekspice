/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Output
*/

#include "Special.hpp"

#include "src/parser/Exception.hpp"

nts::Tristate nts::OutputComponent::compute(const std::size_t pin)
{
    if (pin != 1)
        throw ExceptionInvalidPin("Output: Invalid pin");
    return _pins[pin].compute();
}
