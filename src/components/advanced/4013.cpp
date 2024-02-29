/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** 4013
*/

#include "src/IComponent.hpp"

nts::Tristate nts::Gates4013::compute(std::size_t pin)
{
    if (_pins.compute(4) == nts::True) {
        _outPins[1] = _pins.compute(6);
        _outPins[2] = nts::True;
    } else if (_pins.compute(6) == nts::True) {
        _outPins[1] = nts::True;
        _outPins[2] = nts::False;
    } else if (_pins.compute(3) == nts::True) {
        if (_pins.compute(5) == nts::True) {
            _outPins[1] = nts::True;
            _outPins[2] = nts::False;
        } else {
            _outPins[1] = nts::False;
            _outPins[2] = nts::True;
        }
    }

    if (_pins.compute(10) == nts::True) {
        _outPins[13] = _pins.compute(8);
        _outPins[12] = nts::True;
    } else if (_pins.compute(8) == nts::True) {
        _outPins[13] = nts::True;
        _outPins[12] = nts::False;
    } else if (_pins.compute(11) == nts::True) {
        if (_pins.compute(9) == nts::True) {
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
            throw std::runtime_error("Bad pin");
    }
}
