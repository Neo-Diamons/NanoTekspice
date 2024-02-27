/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Circuit
*/

#include "Circuit.hpp"

#include <iostream>

#include "Factory.hpp"

bool Circuit::addComponent(const std::string &type, const std::string &name)
{
    for (auto &component : _components)
        if (std::get<0>(*component) == name)
            return false;

    std::shared_ptr<std::tuple<std::string, std::shared_ptr<nts::IComponent>>> newComponent = std::make_shared<std::tuple<std::string, std::shared_ptr<nts::IComponent>>>(
        name,
        Factory::createComponent(type)
    );
    if (std::get<1>(*newComponent) == nullptr)
        return false;

    _components.push_back(newComponent);
    if (type == "input" || type == "clock")
        _inputs.push_back(_components.back());
    if (type == "output")
        _outputs.push_back(_components.back());
    return true;
}

void Circuit::sortComponents()
{
    _inputs.sort([](const std::shared_ptr<std::tuple<std::string, std::shared_ptr<nts::IComponent>>> &a, const std::shared_ptr<std::tuple<std::string, std::shared_ptr<nts::IComponent>>> &b) {
        return std::get<0>(*a) < std::get<0>(*b);
    });
    _outputs.sort([](const std::shared_ptr<std::tuple<std::string, std::shared_ptr<nts::IComponent>>> &a, const std::shared_ptr<std::tuple<std::string, std::shared_ptr<nts::IComponent>>> &b) {
        return std::get<0>(*a) < std::get<0>(*b);
    });
}

void Circuit::simulate()
{
    _tick++;
    for (auto &input : _inputs)
        std::dynamic_pointer_cast<nts::InputComponents>(std::get<1>(*input))->simulate(_tick);
    for (auto &output : _outputs)
        std::dynamic_pointer_cast<nts::OutputComponent>(std::get<1>(*output))->simulate(_tick);
}

bool Circuit::setValues(const std::string &name, const std::string &value)
{
    for (auto &input : _inputs)
        if (std::get<0>(*input) == name) {
            std::dynamic_pointer_cast<nts::InputComponents>(std::get<1>(*input))->setState(Factory::stringToTristate(value));
            return true;
        }
    return false;
}

bool Circuit::addLink(const std::string &comp1, std::size_t pin1, const std::string &comp2, std::size_t pin2)
{
    std::shared_ptr<nts::IComponent> component1 = nullptr;
    std::shared_ptr<nts::IComponent> component2 = nullptr;

    for (auto &component : _components) {
        if (std::get<0>(*component) == comp1)
            component1 = std::get<1>(*component);
        if (std::get<0>(*component) == comp2)
            component2 = std::get<1>(*component);
    }

    if (component1 == nullptr || component2 == nullptr)
        return false;

    component2->setLink(pin2, component1, pin1);
    return true;
}

std::ostream &operator<<(std::ostream &os, const Circuit &circuit)
{
    os << "tick: " << circuit._tick << std::endl;
    os << "input(s):" << std::endl;
    for (auto &input : circuit._inputs)
        os << "  " << std::get<0>(*input) << ": " << std::dynamic_pointer_cast<nts::InputComponents>(std::get<1>(*input))->compute(1) << std::endl;
    os << "output(s):" << std::endl;
    for (auto &output : circuit._outputs)
        os << "  " << std::get<0>(*output) << ": " << std::dynamic_pointer_cast<nts::OutputComponent>(std::get<1>(*output))->compute(1) << std::endl;
    return os;
}
