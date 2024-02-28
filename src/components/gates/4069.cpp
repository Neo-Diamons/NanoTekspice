/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** 4069
*/

#include "Gates.hpp"

nts::Tristate nts::Gates4069::compute(const std::size_t pin)
{
    switch (pin) {
        case 2:
            return !_pins[1].compute();
        case 4:
            return !_pins[3].compute();
        case 6:
            return !_pins[5].compute();
        case 8:
            return !_pins[9].compute();
        case 10:
            return !_pins[11].compute();
        case 12:
            return !_pins[13].compute();
        default:
            return checkPin("4069", pin);
    }
}
