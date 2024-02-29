/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentFactory
*/

#ifndef NANOTEKSPICE_COMPONENTFACTORY_HPP_
    #define NANOTEKSPICE_COMPONENTFACTORY_HPP_

    #include <exception>
    #include <functional>
    #include <memory>
    #include <string>

    #include "../Circuit.hpp"
    #include "../Exception.hpp"
    #include "IComponent.hpp"

namespace nts {
    class ComponentFactory {
        private:
            static const std::map<const char * const, std::function<std::unique_ptr<IComponent>(const Circuit &, const std::string &)>> _constructors;
            Circuit &_circuit;

        public:
            ComponentFactory(Circuit &circuit)
                : _circuit(circuit)
            {}

            void create(const std::string &type, const std::string &name) const;

            class Exception : public nts::Exception {
                public:
                    const std::string &getType() const noexcept { return _type; }
                    const std::string &getName() const noexcept { return _name; }

                protected:
                    Exception(const std::string &type, const std::string &name)
                        : _type(type), _name(name)
                    {}

                    const std::string _type;
                    const std::string _name;
            };

            class InvalidTypeException : public Exception {
                public:
                    InvalidTypeException(const std::string &type, const std::string &name)
                        : Exception(type, name)
                    {}

                protected:
                    [[nodiscard]] std::string makeMessage() const noexcept final;
            };

            class ComponentExistsException : public Exception {
                public:
                    ComponentExistsException(const std::string &type, const std::string &name)
                        : Exception(type, name)
                    {}

                protected:
                    [[nodiscard]] std::string makeMessage() const noexcept final;
            };
    };
}

#endif /* !NANOTEKSPICE_COMPONENTFACTORY_HPP_ */
