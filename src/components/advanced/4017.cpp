/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** 4017
*/

#include "Advanced.hpp"

void nts::Gates4017::simulate(const std::size_t tick)
{
    if (tick == _lastTick)
        return;
    _lastTick = tick;
    for (auto &pin: _pins)
        pin.second.simulate(tick);

    if (_pins[15].compute() == True)
        _count = 0;
    else if (_pins[13].compute() == True
        && _pins[14].compute() == True)
        _count = (_count + 1) % 10;
}

nts::Tristate nts::Gates4017::compute(const std::size_t pin)
{
    switch (pin) {
        case 3:
            return _count == 0 ? True : False;
        case 2:
            return _count == 1 ? True : False;
        case 4:
            return _count == 2 ? True : False;
        case 7:
            return _count == 3 ? True : False;
        case 10:
            return _count == 4 ? True : False;
        case 1:
            return _count == 5 ? True : False;
        case 5:
            return _count == 6 ? True : False;
        case 6:
            return _count == 7 ? True : False;
        case 9:
            return _count == 8 ? True : False;
        case 11:
            return _count == 9 ? True : False;
        case 12:
            return _count <= 4 ? True : False;
        default:
            return checkPin("4017", pin);
    }
}
