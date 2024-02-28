/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** And
*/

#include "Elementary.hpp"

nts::Tristate nts::AndComponent::compute(const std::size_t pin)
{
    switch (pin) {
        case 3:
            return _pins[1].compute() && _pins[2].compute();
        default:
            return checkPin("And", pin);
    }
}
