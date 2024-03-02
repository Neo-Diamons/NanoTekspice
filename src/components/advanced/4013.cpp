/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** 4013
*/

#include "Advanced.hpp"

void nts::Gates4013::simulate(const std::size_t tick)
{
    if (tick == _lastTick)
        return;
    _lastTick = tick;
    for (auto &[fst, snd]: _pins)
        snd.simulate(tick);

    if (_pins[4].compute() == True) {
        _outPins[1] = _pins[6].compute();
        _outPins[2] = True;
    } else if (_pins[6].compute() == True) {
        _outPins[1] = True;
        _outPins[2] = False;
    } else if (_pins[3].compute() == True) {
        if (_pins[5].compute() == True) {
            _outPins[1] = True;
            _outPins[2] = False;
        } else {
            _outPins[1] = False;
            _outPins[2] = True;
        }
    }
    
    if (_pins[10].compute() == True) {
        _outPins[13] = _pins[8].compute();
        _outPins[12] = True;
    } else if (_pins[8].compute() == True) {
        _outPins[13] = True;
        _outPins[12] = False;
    } else if (_pins[11].compute() == True) {
        if (_pins[9].compute() == True) {
            _outPins[13] = True;
            _outPins[12] = False;
        } else {
            _outPins[13] = False;
            _outPins[12] = True;
        }
    }
}

nts::Tristate nts::Gates4013::compute(const std::size_t pin)
{
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
            return checkPin("4013", pin);
    }
}
