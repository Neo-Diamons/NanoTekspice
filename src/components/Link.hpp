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

    #include "IComponent.hpp"

namespace nts {
    class Link {
        public:
            Link() = default;

            Link(const std::shared_ptr<IComponent> &component, std::size_t pin)
                : _component(component), _pin(pin)
            {};

            [[nodiscard]] Tristate compute() const;

            class InvalidPinException : public std::exception {
                public:
                    InvalidPinException(std::size_t pin, std::shared_ptr<IComponent> component, bool isOutputPin = false)
                        : _pin(pin), _component(component), _isOutputPin(isOutputPin), _message(this->makeMessage())
                    {}

                    [[nodiscard]] const char *what() const noexcept final;
                    std::size_t getPin() const { return _pin; }
                    std::shared_ptr<IComponent> getComponent() const { return _component; }
                    bool isOutputPin() const { return _isOutputPin; }

                private:
                    const std::size_t _pin;
                    const std::shared_ptr<IComponent> _component;
                    const bool _isOutputPin;
                    const std::string _message;
                    [[nodiscard]] std::string makeMessage() const;
            };

        private:
            std::shared_ptr<IComponent> _component;
            std::size_t _pin;
    };
}

#endif /* !NANOTEKSPICE_LINK_HPP_ */
