/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Not
*/

#include "Elementary.hpp"

nts::Tristate nts::NotComponent::compute(const std::size_t pin)
{
    switch (pin) {
        case 2:
            return !_pins[1].compute();
        default:
            return checkPin("Not", pin);
    }
}
