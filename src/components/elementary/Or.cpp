/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Or
*/

#include "src/IComponent.hpp"

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    switch (pin - 2) {
        case 1:
            return _pins.compute(1) | _pins.compute(2);
        default:
            throw std::runtime_error("Bad pin");
    }
}
