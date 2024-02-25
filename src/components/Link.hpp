/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Link
*/

#ifndef NANOTEKSPICE_LINK_HPP_
    #define NANOTEKSPICE_LINK_HPP_

    #include <cstddef>
    #include <exception>
    #include <memory>
    #include <string>

    #include "../Exception.hpp"
    #include "IComponent.hpp"

namespace nts {
    class Link {
        public:
            Link() = default;

            Link(const std::shared_ptr<IComponent> &component, std::size_t pin)
                : _component(component), _pin(pin)
            {};

            [[nodiscard]] Tristate compute() const;

            class InvalidPinException : public Exception {
                public:
                    InvalidPinException(std::size_t pin, const std::string &componentName, bool isOutputPin = false)
                        : _pin(pin), _componentName(componentName), _isOutputPin(isOutputPin)
                    {}

                    std::size_t getPin() const { return _pin; }
                    const std::string &getComponentName() const { return _componentName; }
                    bool isOutputPin() const { return _isOutputPin; }

                protected:
                    [[nodiscard]] std::string makeMessage() const final;

                private:
                    const std::size_t _pin;
                    const std::string _componentName;
                    const bool _isOutputPin;
            };

        private:
            std::shared_ptr<IComponent> _component;
            std::size_t _pin;
    };
}

#endif /* !NANOTEKSPICE_LINK_HPP_ */
