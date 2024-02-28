/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** AComponent
*/

#include "AComponent.hpp"

#include <algorithm>

#include "src/parser/Exception.hpp"

bool nts::AComponent::asInput(const std::size_t pin) const
{
    return std::ranges::find(_inputs, pin) != _inputs.end();
}

bool nts::AComponent::asOutput(const std::size_t pin) const
{
    return std::ranges::find(_outputs, pin) != _outputs.end();
}

nts::Tristate nts::AComponent::checkPin(const std::string &name, const std::size_t pin)
{
    if (!asInput(pin) && !asOutput(pin))
        throw ExceptionInvalidPin(name + ": Invalid pin");
    return !_pins.contains(pin) ? Undefined : _pins[pin].compute();
}

std::map<std::size_t, nts::Link> &nts::AComponent::getPins()
{
    return _pins;
}

void nts::AComponent::simulate(const std::size_t tick)
{
    if (tick == _lastTick)
        return;
    _lastTick = tick;
    for (auto &[fst, snd]: _pins)
        snd.simulate(tick);
}
