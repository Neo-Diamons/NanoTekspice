/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** 4069
*/

#include "src/IComponent.hpp"

nts::Tristate nts::Gates4069::compute(std::size_t pin)
{
    switch (pin) {
        case 2:
            return !_pins.compute(1);
        case 4:
            return !_pins.compute(3);
        case 6:
            return !_pins.compute(5);
        case 8:
            return !_pins.compute(9);
        case 10:
            return !_pins.compute(11);
        case 12:
            return !_pins.compute(13);
        default:
            throw std::runtime_error("Bad pin");
    }
}
