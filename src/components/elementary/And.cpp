/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** And
*/

#include "src/IComponent.hpp"

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    switch (pin - 2) {
        case 1:
            return _pins.compute(1) & _pins.compute(2);
        default:
            throw std::runtime_error("Bad pin");
    }
}
