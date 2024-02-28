/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** 4011
*/

#include "Gates.hpp"

nts::Tristate nts::Gates4011::compute(const std::size_t pin)
{
    switch (pin) {
        case 3:
            return _pins[1].compute() & _pins[2].compute();
        case 4:
            return _pins[5].compute() & _pins[6].compute();
        case 10:
            return _pins[8].compute() & _pins[9].compute();
        case 11:
            return _pins[12].compute() & _pins[13].compute();
        default:
            return checkPin("4011", pin);
    }
}
