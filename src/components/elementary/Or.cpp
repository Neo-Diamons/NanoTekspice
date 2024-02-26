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
            return _pins[1].compute() | _pins[2].compute();
        default:
            throw std::runtime_error("Bad pin");
    }
}
