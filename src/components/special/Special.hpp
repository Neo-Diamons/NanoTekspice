/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** SpecialComponent
*/

#ifndef NANOTEKSPICE_SPECIAL_HPP
#define NANOTEKSPICE_SPECIAL_HPP

#include "../AComponent.hpp"

namespace nts {
    class ValueComponent : public AComponent {
    public:
        ValueComponent(const std::list<std::size_t> &inputs, const std::list<std::size_t> &outputs)
            : AComponent(inputs, outputs)
        {}

        void simulate([[maybe_unused]] const std::size_t tick) override
        {}
    };

    class InputComponents : public AComponent {
    public:
        InputComponents(const std::list<std::size_t> &inputs, const std::list<std::size_t> &outputs)
            : AComponent(inputs, outputs)
        {}

        virtual void setState(Tristate state) = 0;
    };

    // Special components
    class InputComponent final : public InputComponents {
    private:
        Tristate _state = Undefined;
        Tristate _oldState = Undefined;

    public:
        InputComponent() : InputComponents({}, {1})
        {}

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
        void setState(Tristate state) override;
    };

    class OutputComponent final : public AComponent {
    public:
        OutputComponent() : AComponent({1}, {})
        {}

        Tristate compute(std::size_t pin) override;
    };

    class TrueComponent final : public ValueComponent {
    public:
        TrueComponent() : ValueComponent({}, {1})
        {}

        Tristate compute(std::size_t pin) override;
    };

    class FalseComponent final : public ValueComponent {
    public:
        FalseComponent() : ValueComponent({}, {1})
        {}

        Tristate compute(std::size_t pin) override;
    };

    class ClockComponent final : public InputComponents {
    private:
        Tristate _state = Undefined;
        Tristate _oldState = Undefined;

    public:
        ClockComponent() : InputComponents({}, {1})
        {}

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
        void setState(Tristate state) override;
    };
}

#endif //NANOTEKSPICE_SPECIAL_HPP
