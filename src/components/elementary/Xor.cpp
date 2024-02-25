/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Xor
*/

#include "src/IComponent.hpp"

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    switch (pin - 2) {
        case 1:
            return _pins[1].compute() ^ _pins[2].compute();
        default:
            return checkPin("Xor", pin);
    }
}
