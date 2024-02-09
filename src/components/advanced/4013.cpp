/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** 4013
*/

#include "src/IComponent.hpp"

nts::Tristate nts::Gates4013::compute(std::size_t pin)
{
    if (_pins[4].compute() == nts::True) {
        _outPins[1] = _pins[6].compute();
        _outPins[2] = nts::True;
    } else if (_pins[6].compute() == nts::True) {
        _outPins[1] = nts::True;
        _outPins[2] = nts::False;
    } else if (_pins[3].compute() == nts::True) {
        if (_pins[5].compute() == nts::True) {
            _outPins[1] = nts::True;
            _outPins[2] = nts::False;
        } else {
            _outPins[1] = nts::False;
            _outPins[2] = nts::True;
        }
    }

    if (_pins[10].compute() == nts::True) {
        _outPins[13] = _pins[8].compute();
        _outPins[12] = nts::True;
    } else if (_pins[8].compute() == nts::True) {
        _outPins[13] = nts::True;
        _outPins[12] = nts::False;
    } else if (_pins[11].compute() == nts::True) {
        if (_pins[9].compute() == nts::True) {
            _outPins[13] = nts::True;
            _outPins[12] = nts::False;
        } else {
            _outPins[13] = nts::False;
            _outPins[12] = nts::True;
        }
    }

    switch (pin) {
        case 1:
            return _outPins[1];
        case 2:
            return _outPins[2];
        case 12:
            return _outPins[12];
        case 13:
            return _outPins[13];
        default:
            throw AComponent::Exception("4013: Invalid pin");
    }
}
