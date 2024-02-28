/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** AComponent
*/

#include "AComponent.hpp"

#include <algorithm>

#include "src/parser/Exception.hpp"

bool nts::AComponent::asInput(std::size_t pin) const
{
    return std::find(_inputs.begin(), _inputs.end(), pin) != _inputs.end();
}

bool nts::AComponent::asOutput(std::size_t pin) const
{
    return std::find(_outputs.begin(), _outputs.end(), pin) != _outputs.end();
}

nts::Tristate nts::AComponent::checkPin(const std::string &name, std::size_t pin)
{
    if (!asInput(pin) && !asOutput(pin))
        throw ExceptionInvalidPin(name + ": Invalid pin");
    return _pins.find(pin) == _pins.end()
        ? nts::Undefined
        : _pins[pin].compute();
}

std::map<std::size_t, nts::Link> &nts::AComponent::getPins()
{
    return _pins;
}

void nts::AComponent::simulate(std::size_t tick)
{
    if (tick == _lastTick)
        return;
    _lastTick = tick;
    for (auto &pin: _pins)
        pin.second.simulate(tick);
}
