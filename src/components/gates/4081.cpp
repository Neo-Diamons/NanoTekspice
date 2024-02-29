/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** 4081
*/

#include "src/IComponent.hpp"

nts::Tristate nts::Gates4081::compute(std::size_t pin)
{
    switch (pin) {
        case 3:
            return _pins.compute(1) & _pins.compute(2);
        case 4:
            return _pins.compute(5) & _pins.compute(6);
        case 10:
            return _pins.compute(8) & _pins.compute(9);
        case 11:
            return _pins.compute(12) & _pins.compute(13);
        default:
            throw std::runtime_error("Bad pin");
    }
}
