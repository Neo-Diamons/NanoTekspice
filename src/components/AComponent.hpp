/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** AComponent
*/

#ifndef NANOTEKSPICE_ACOMPONENT_HPP
#define NANOTEKSPICE_ACOMPONENT_HPP

#include <map>

#include "IComponent.hpp"
#include "Link.hpp"

namespace nts {
    class AComponent : public IComponent {
    protected:
        std::map<std::size_t, Link> _pins{};
        std::size_t _lastTick = 0;
        std::size_t _nbPins = 0;

        Tristate checkPin(const std::string &name, std::size_t pin);

    public:
        class ExceptionInvalidPin : public std::exception {
        private:
            std::string _message;

        public:
            explicit ExceptionInvalidPin(std::string message);

            [[nodiscard]] const char *what() const noexcept override;
        };

        [[nodiscard]] bool asPin(std::size_t pin) const;

        void setLink(std::size_t pin, std::shared_ptr<IComponent> other, std::size_t otherPin) override;
        void simulate(std::size_t tick) override;
    };
}

#endif //NANOTEKSPICE_ACOMPONENT_HPP
