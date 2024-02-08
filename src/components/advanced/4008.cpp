/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** 4008
*/


#include "src/IComponent.hpp"

nts::Tristate nts::Gates4008::add(int idA, int idB, nts::Tristate carry)
{
    nts::Tristate a = _pins[idA].compute();
    nts::Tristate b = _pins[idB].compute() ^ carry;

    nts::Tristate sum = a ^ b ^ _outPins[14];
    _outPins[14] = (a && b) || (_outPins[14] && (a ^ b));

    return sum;
}

nts::Tristate nts::Gates4008::compute(std::size_t pin)
{
    nts::Tristate carry = _pins[9].compute();

    _outPins = {
        {10, nts::Undefined},
        {11, nts::Undefined},
        {12, nts::Undefined},
        {13, nts::Undefined},
        {14, carry},
    };

    _outPins[10] = add(7, 6, carry);
    _outPins[11] = add(5, 4, carry);
    _outPins[12] = add(3, 2, carry);
    _outPins[13] = add(1, 15, carry);

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
            throw AComponent::Exception("4008: Invalid pin");
    }
}
