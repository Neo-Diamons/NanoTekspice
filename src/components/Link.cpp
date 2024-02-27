/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Link
*/

#include "Link.hpp"

nts::Link::Link()
{
    _pin = 0;
    _component = nullptr;
}

nts::Link::Link(const std::shared_ptr<IComponent> &component, std::size_t pin)
{
    _pin = pin;
    _component = component;
}

void nts::Link::simulate(std::size_t tick)
{
    _component->simulate(tick);
}

nts::Tristate nts::Link::compute() const
{
    if (_pin == 0)
        return Undefined;
    return _component->compute(_pin);
}
