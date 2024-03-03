/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** 4001
*/

#include "Gates.hpp"

nts::Tristate nts::Gates4001::compute(const std::size_t pin)
{
    if (std::ranges::find(inProccess, pin) != inProccess.end())
        return Undefined;

    inProccess.push_back(pin);
    Tristate ret;
    switch (pin) {
        case 3:
            ret = _pins[1].compute() | _pins[2].compute();
            inProccess.pop_back();
            return ret;
        case 4:
            ret = _pins[5].compute() | _pins[6].compute();
            inProccess.pop_back();
            return ret;
        case 10:
            ret = _pins[8].compute() | _pins[9].compute();
            inProccess.pop_back();
            return ret;
        case 11:
            ret = _pins[12].compute() | _pins[13].compute();
            inProccess.pop_back();
            return ret;
        default:
            inProccess.pop_back();
            return checkPin("4001", pin);
    }
}
