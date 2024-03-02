/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** 4008
*/

#include "Advanced.hpp"

nts::Tristate nts::Gates4008::add(const u_int8_t idA, const u_int8_t idB, const Tristate carry)
{
    const Tristate a = _pins[idA].compute();
    const Tristate b = _pins[idB].compute();

    _outPins[14] = ((a ^ b) && carry) || (a && b);
    return (a ^ b) ^ carry;
}

nts::Tristate nts::Gates4008::compute(const std::size_t pin)
{
    Tristate carry = _pins[9].compute();

    _outPins = {
        {10, Undefined},
        {11, Undefined},
        {12, Undefined},
        {13, Undefined},
        {14, carry},
    };

    _outPins[10] = add(7, 6, _outPins[14]);
    _outPins[11] = add(5, 4, _outPins[14]);
    _outPins[12] = add(3, 2, _outPins[14]);
    _outPins[13] = add(1, 15, _outPins[14]);

    switch (pin) {
        case 10:
            return _outPins[10];
        case 11:
            return _outPins[11];
        case 12:
            return _outPins[12];
        case 13:
            return _outPins[13];
        case 14:
            return _outPins[14];
        default:
            return checkPin("4008", pin);
    }
}
