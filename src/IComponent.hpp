/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** IComponent
*/

#ifndef NANOTEKSPICE_ICOMPONENT_HPP
#define NANOTEKSPICE_ICOMPONENT_HPP

#include <memory>
#include <map>

#include "Tristate.hpp"
#include "components/IComponent.hpp"

namespace nts {
    class Link {
    public:
        Link() : _pin(0)
        {};

        Link(const std::shared_ptr<IComponent> &component, std::size_t pin)
            : _component(component), _pin(pin)
        {};

        [[nodiscard]] nts::Tristate compute() const
        {
            return _component->compute(this->_pin);
        }

    private:
        std::shared_ptr<IComponent> _component;
        std::size_t _pin;
    };

    // Abstract
    class AComponent : public IComponent {
    protected:
        std::map<size_t, Link> _pins{};

    public:
        class Exception : public std::exception {
        private:
            std::string _message;

        public:
            explicit Exception(std::string message);

            [[nodiscard]] const char *what() const noexcept override;
        };

        void setLink(std::size_t pin, std::shared_ptr<IComponent> other, std::size_t otherPin) override;
    };

    class ValueComponent : public AComponent {
    public:
        void setLink([[maybe_unused]] std::size_t pin, [[maybe_unused]] std::shared_ptr<IComponent> other,
            [[maybe_unused]] std::size_t otherPin) final
        {};
    };

    // Special components
    class InputComponent : public AComponent {
    private:
        nts::Tristate _state = nts::Undefined;
        nts::Tristate _oldState = nts::Undefined;

    public:

        nts::Tristate compute(std::size_t pin) override;

        void setState(nts::Tristate state);
    };

    class OutputComponent : public AComponent {
    public:

        nts::Tristate compute(std::size_t pin) override;
    };

    class TrueComponent : public ValueComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class FalseComponent : public ValueComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class ClockComponent : public ValueComponent {
    private:
        nts::Tristate _state = nts::Undefined;

    public:

        nts::Tristate compute(std::size_t pin) override;
    };

    // Elementary components
    class AndComponent : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class OrComponent : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class XorComponent : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class NotComponent : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    // Gates components
    class Gates4001 : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4011 : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4030 : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4069 : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4071 : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4081 : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    // Advanced components
    class Gates4008 : public AComponent {
    private:
        std::map<int, nts::Tristate> _outPins;

        nts::Tristate add(int idA, int idB, nts::Tristate carry);

    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4017 : public AComponent {
    private:
        std::size_t _count = 0;

    public:

        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4013 : public AComponent {
    private:
        std::map<int, nts::Tristate> _outPins = {
            {1, nts::Undefined},
            {2, nts::Undefined},
            {3, nts::Undefined},
            {4, nts::Undefined},
        };

    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4040 : public AComponent {
    private:
        unsigned _count = 0;

    public:

        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif //NANOTEKSPICE_ICOMPONENT_HPP
