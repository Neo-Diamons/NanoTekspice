/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentFactory
*/

#include "Components.hpp"

#include "ComponentFactory.hpp"

using namespace nts;

template<typename T>
concept HasComponentTypeName =
    requires(T t) {
    static_cast<const char *>(T::typeName);
};

template<typename T> requires HasComponentTypeName<T>
static const std::pair<const char * const, std::function<std::unique_ptr<IComponent>(const Circuit &, const std::string &)>> makeConstructorPair()
{
    return {T::typeName, [](const Circuit &circuit, const std::string &name) { return std::make_unique<T>(circuit, name); }};
}

const std::map<const char * const, std::function<std::unique_ptr<IComponent>(const Circuit &, const std::string &)>> ComponentFactory::constructors = {
    makeConstructorPair<InputComponent>(), makeConstructorPair<ClockComponent>(),
    makeConstructorPair<TrueComponent>(), makeConstructorPair<FalseComponent>()
};

[[nodiscard]] std::string ComponentFactory::InvalidTypeException::makeMessage() const noexcept
{
    return "ComponentFactory::InvalidTypeException: Component '" + this->_name
        + "' has type '" + this->_type + "' which is not valid";
}

[[nodiscard]] std::string ComponentFactory::ComponentExistsException::makeMessage() const noexcept
{
    return "ComponentFactory::ComponentExistsException: Cannot create component named '" + this->_name
        + "' of type '" + this->_type + "'; a component with that name already exists";
}

std::unique_ptr<IComponent> ComponentFactory::create(const Circuit &circuit, const std::string &type, const std::string &name,
    const std::list<std::string> &names) const
{
    for (auto n: names)
        if (n == name)
            throw ComponentExistsException(type, name);

    auto constructor = constructors.find(type.c_str());
    if (constructor == constructors.end())
        throw InvalidTypeException(type, name);

    return (*constructor).second(circuit, name);
}
