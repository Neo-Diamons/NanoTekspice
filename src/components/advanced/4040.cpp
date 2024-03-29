/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** 4040
*/

#include "Advanced.hpp"

void nts::Gates4040::simulate(const std::size_t tick)
{
    if (tick == _lastTick)
        return;
    _lastTick = tick;
    for (auto &[fst, snd]: _pins)
        snd.simulate(tick);

    if (_pins[11].compute())
        _count = 0;
    else if (_pins[10].compute())
        _count = (_count + 1) % 0b1000000000000;
}

nts::Tristate nts::Gates4040::compute(const std::size_t pin)
{
    switch (pin) {
        case 9:
            return _count & 0b000000000001 ? True : False;
        case 7:
            return _count & 0b000000000010 ? True : False;
        case 6:
            return _count & 0b000000000100 ? True : False;
        case 5:
            return _count & 0b000000001000 ? True : False;
        case 3:
            return _count & 0b000000010000 ? True : False;
        case 2:
            return _count & 0b000000100000 ? True : False;
        case 4:
            return _count & 0b000001000000 ? True : False;
        case 13:
            return _count & 0b000010000000 ? True : False;
        case 12:
            return _count & 0b000100000000 ? True : False;
        case 14:
            return _count & 0b001000000000 ? True : False;
        case 15:
            return _count & 0b010000000000 ? True : False;
        case 1:
            return _count & 0b100000000000 ? True : False;
        default:
            return checkPin("4040", pin);
    }
}
