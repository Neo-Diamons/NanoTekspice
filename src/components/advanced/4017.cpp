/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** 4017
*/

#include "src/IComponent.hpp"

nts::Tristate nts::Gates4017::compute(std::size_t pin)
{
    if (_pins[15].compute() == nts::Tristate::True)
        _count = 0;
    else if (_pins[13].compute() == nts::Tristate::True
        && _pins[14].compute() == nts::Tristate::True)
        _count = (_count + 1) % 10;

    switch (pin) {
        case 3:
            return _count == 0 ? nts::Tristate::True : nts::Tristate::False;
        case 2:
            return _count == 1 ? nts::Tristate::True : nts::Tristate::False;
        case 4:
            return _count == 2 ? nts::Tristate::True : nts::Tristate::False;
        case 7:
            return _count == 3 ? nts::Tristate::True : nts::Tristate::False;
        case 10:
            return _count == 4 ? nts::Tristate::True : nts::Tristate::False;
        case 1:
            return _count == 5 ? nts::Tristate::True : nts::Tristate::False;
        case 5:
            return _count == 6 ? nts::Tristate::True : nts::Tristate::False;
        case 6:
            return _count == 7 ? nts::Tristate::True : nts::Tristate::False;
        case 9:
            return _count == 8 ? nts::Tristate::True : nts::Tristate::False;
        case 11:
            return _count == 9 ? nts::Tristate::True : nts::Tristate::False;
        case 12:
            return _count <= 4 ? nts::Tristate::True : nts::Tristate::False;
        default:
            throw std::runtime_error("Bad pin");
    }
}
