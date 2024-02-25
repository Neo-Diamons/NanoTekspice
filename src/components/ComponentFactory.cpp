/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentFactory
*/

#include <algorithm>
#include <list>
#include <memory>
#include <sstream>

#include "Components.hpp"

#include "ComponentFactory.hpp"
#include "IComponent.hpp"
#include "IInputComponent.hpp"

using namespace nts;

const std::map<const char *, std::function<std::shared_ptr<IComponent>(const Circuit &, const std::string &)>> ComponentFactory::_constructors = {
    {InputComponent::name, [](const Circuit &circuit, const std::string &name){ return std::make_shared<InputComponent>(circuit, name); }},
    {ClockComponent::name, [](const Circuit &circuit, const std::string &name){ return std::make_shared<ClockComponent>(circuit, name); }},
    {TrueComponent::name, [](const Circuit &circuit, const std::string &name){ return std::make_shared<TrueComponent>(circuit, name); }},
    {FalseComponent::name, [](const Circuit &circuit, const std::string &name){ return std::make_shared<FalseComponent>(circuit, name); }}
};

[[nodiscard]] std::string ComponentFactory::InvalidTypeException::makeMessage() const
{
    std::stringstream message;

    message << "ComponentFactory::InvalidTypeException: Component '" << this->_name
        << "' has type '" << this->_type << "' which is not valid.";

    return message.str();
}

[[nodiscard]] std::string ComponentFactory::ComponentExistsException::makeMessage() const
{
    std::stringstream message;

    message << "ComponentFactory::ComponentExistsException: Cannot create component named '" << this->_name
        << "' of type '" << this->_type << "'; a component with that name already exists.";

    return message.str();
}

void ComponentFactory::create(const std::string &type, const std::string &name) const
{
    const std::list<std::reference_wrapper<const std::string>> &names = this->_circuit.getNames();
    for (auto n: names)
        if (n.get() == name)
            throw ComponentExistsException(type, name);

    if (type == "output") {
        this->_circuit.addOutput(name);
        return;
    }

    auto constructor = _constructors.find(type.c_str());
    if (constructor == _constructors.end())
        throw InvalidTypeException(type, name);

    this->_circuit.addComponent((*constructor).second(_circuit, name));
}
