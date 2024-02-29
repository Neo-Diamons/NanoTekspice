/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Circuit
*/

#include "Circuit.hpp"

#include <iostream>

#include "Exception.hpp"
#include "Factory.hpp"

void nts::Circuit::addComponent(const std::string &type, const std::string &value)
{
    for (auto &component : _components)
        if (std::get<0>(*component) == value)
            throw ExceptionDuplicateComponent(value);

    const auto newComponent = std::make_shared<std::tuple<std::string, std::shared_ptr<nts::IComponent>>>(
        value,
        Factory::createComponent(type)
    );

    _components.push_back(newComponent);
    if (type == "input" || type == "clock")
        _inputs.push_back(_components.back());
    if (type == "output")
        _outputs.push_back(_components.back());
}

void nts::Circuit::sortComponents()
{
    _inputs.sort([](const std::shared_ptr<std::tuple<std::string, std::shared_ptr<IComponent>>> &a, const std::shared_ptr<std::tuple<std::string, std::shared_ptr<IComponent>>> &b) {
        return std::get<0>(*a) < std::get<0>(*b);
    });
    _outputs.sort([](const std::shared_ptr<std::tuple<std::string, std::shared_ptr<IComponent>>> &a, const std::shared_ptr<std::tuple<std::string, std::shared_ptr<IComponent>>> &b) {
        return std::get<0>(*a) < std::get<0>(*b);
    });
}

void nts::Circuit::simulate()
{
    _tick++;
    for (auto &input : _inputs)
        std::dynamic_pointer_cast<InputComponents>(std::get<1>(*input))->simulate(_tick);
    for (auto &output : _outputs)
        std::dynamic_pointer_cast<OutputComponent>(std::get<1>(*output))->simulate(_tick);
}

void nts::Circuit::setValue(const std::string &name, const std::string &value) const
{
    for (auto &input : _inputs)
        if (std::get<0>(*input) == name) {
            std::dynamic_pointer_cast<InputComponents>(std::get<1>(*input))->setState(toTristate(value));
            return;
        }
    throw std::invalid_argument("Unknown input: " + name);
}

void nts::Circuit::addLink(const std::string &comp1, const std::size_t pin1, const std::string &comp2, const std::size_t pin2) const
{
    std::shared_ptr<IComponent> component1 = nullptr;
    std::shared_ptr<IComponent> component2 = nullptr;

    for (auto &component : _components) {
        if (std::get<0>(*component) == comp1)
            component1 = std::get<1>(*component);
        if (std::get<0>(*component) == comp2)
            component2 = std::get<1>(*component);
    }

    if (component1 == nullptr)
        throw ExceptionUnknowComponent(comp1);
    if (component2 == nullptr)
        throw ExceptionUnknowComponent(comp2);

    Link::setLink(component1, pin1, component2, pin2);
}

std::size_t nts::Circuit::getTick() const
{
    return _tick;
}

const Components &nts::Circuit::getInputs() const
{
    return _inputs;
}

const Components &nts::Circuit::getOutputs() const
{
    return _outputs;
}

std::ostream &nts::operator<<(std::ostream &os, const Circuit &circuit)
{
    os << "tick: " << circuit.getTick();
    os << "\ninput(s):";
    for (auto &input : circuit.getInputs())
        os << "\n  " << std::get<0>(*input) << ": " << std::dynamic_pointer_cast<InputComponents>(std::get<1>(*input))->compute(1);
    os << "\noutput(s):";
    for (auto &output : circuit.getOutputs())
        os << "\n  " << std::get<0>(*output) << ": " << std::dynamic_pointer_cast<OutputComponent>(std::get<1>(*output))->compute(1);
    os << std::endl;
    return os;
}
