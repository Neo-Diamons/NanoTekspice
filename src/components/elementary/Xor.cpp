/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Xor
*/

#include "Elementary.hpp"

nts::Tristate nts::XorComponent::compute(const std::size_t pin)
{
    switch (pin) {
        case 3:
            return _pins[1].compute() ^ _pins[2].compute();
        default:
            return checkPin("Xor", pin);
    }
}
