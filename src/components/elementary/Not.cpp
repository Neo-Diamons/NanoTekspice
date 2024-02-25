/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Not
*/

#include "src/IComponent.hpp"

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    switch (pin - 1) {
        case 1:
            return !_pins[1].compute();
        default:
            return checkPin("Not", pin);
    }
}
