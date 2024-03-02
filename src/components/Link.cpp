/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Link
*/

#include "Link.hpp"
#include "src/parsing/Exception.hpp"

nts::Link::Link()
{
    _pin = 0;
    _component = nullptr;
}

nts::Link::Link(const std::shared_ptr<IComponent> &component, const std::size_t pin)
{
    _pin = pin;
    _component = component;
}

void nts::Link::simulate(const std::size_t tick) const
{
    if (_pin == 0)
        return;
    _component->simulate(tick);
}

nts::Tristate nts::Link::compute() const
{
    if (_pin == 0)
        return Undefined;
    return _component->compute(_pin);
}

void nts::Link::setLink(const std::shared_ptr<IComponent> &component, const std::size_t pin,
                        const std::shared_ptr<IComponent> &toComponent, const std::size_t toPin)
{
    if (component->asInput(pin) && toComponent->asOutput(toPin))
        component->getPins()[pin] = Link(toComponent, toPin);
    else if (component->asOutput(pin) && toComponent->asInput(toPin))
        toComponent->getPins()[toPin] = Link(component, pin);
    else
        throw ExceptionInvalidPin("Invalid link");
}
