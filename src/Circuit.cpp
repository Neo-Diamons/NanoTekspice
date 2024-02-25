/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Circuit
*/

#include <algorithm>
#include <cstddef>
#include <functional>
#include <memory>
#include <sstream>
#include <stdexcept>

#include "Circuit.hpp"
#include "Tristate.hpp"
#include "components/IComponent.hpp"
#include "components/IInputComponent.hpp"

using namespace nts;

[[nodiscard]] std::list<std::reference_wrapper<const std::string>> Circuit::getNames() const
{
    std::list<std::reference_wrapper<const std::string>> names;

    std::for_each(this->_components.begin(), this->_components.end(), [&names](std::shared_ptr<nts::IComponent> c){
        names.push_back(c->getName());
    });
    std::for_each(this->_outputs.begin(), this->_outputs.end(), [&names](const auto &o){
        names.push_back(o.first);
    });

    return names;
}

void Circuit::addComponent(std::shared_ptr<IComponent> component)
{
    std::shared_ptr<IInputComponent> inputComponent = std::dynamic_pointer_cast<IInputComponent>(component);
    if (inputComponent != nullptr)
        this->_inputs.push_back(std::pair<std::shared_ptr<nts::IInputComponent>, nts::Tristate>(inputComponent, inputComponent->getState()));
    this->_components.push_back(component);
}

void Circuit::addOutput(const std::string &name)
{
    this->_iPins.insert(this->_nextPin);
    this->_outputs[name] = std::pair<std::size_t, nts::Tristate>(this->_nextPin++, Tristate::Undefined);
}

[[nodiscard]] std::string Circuit::ComponentNotFoundException::makeMessage() const
{
    std::stringstream message;

    message << "Circuit::ComponentNotFoundException: Component '" << this->_name << "' does not exist.";

    return message.str();
}

void Circuit::linkComponents(const std::string &in, std::size_t iPin, const std::string &out, std::size_t oPin)
{
    auto inComponent = std::find_if(_components.begin(), _components.end(), [&in](const auto &component) {
        return component->getName() == in;
    });

    if (inComponent == _components.end())
        throw ComponentNotFoundException(in);

    if (_outputs.contains(out)) {
        if (oPin != 1)
            throw Link::InvalidPinException(oPin, this->getName());

        this->setLink(_outputs.at(out).first, *inComponent, iPin);
    } else {
        auto outComponent = std::find_if(_components.begin(), _components.end(), [&out](const auto &component) {
            return component->getName() == out;
        });

        if (outComponent == _components.end())
            throw ComponentNotFoundException(in);

        (*outComponent)->setLink(oPin, *inComponent, iPin);
    }

}

const std::set<size_t> Circuit::oPins = {};

std::pair<const std::set<size_t>&, const std::set<size_t>&> Circuit::getValidPins()
{
    return std::pair<const std::set<size_t>&, const std::set<size_t>&>(this->_iPins, oPins);
}

Tristate Circuit::compute(std::size_t)
{
    throw std::runtime_error("No input pins on a Circuit");
}

std::size_t Circuit::getTick() const
{
    return this->_tick;
}
void Circuit::display()
{
    this->_os << "tick: " << this->_tick
        << "\ninput(s):\n";
    std::for_each(this->_inputs.begin(), this->_inputs.end(), [this](const auto &i){
        this->_os << "  " << i.first->getName() << ": " << i.second << '\n';
    });
    this->_os << "output(s):\n";
    std::for_each(this->_outputs.begin(), this->_outputs.end(), [this](const auto &o){
        this->_os << "  " << o.first << ": " << o.second.second << '\n';
    });
}

void Circuit::simulate()
{
    _tick++;
    std::for_each(this->_outputs.begin(), this->_outputs.end(), [this](auto &o){
        o.second.second = this->_pins[o.second.first].compute();
    });
    std::for_each(this->_inputs.begin(), this->_inputs.end(), [this](auto &i){
        i.second = i.first->getState();
    });
}