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
        void simulate([[maybe_unused]] std::size_t tick) override
        {};

        void setLink([[maybe_unused]] std::size_t pin, [[maybe_unused]] std::shared_ptr<IComponent> other,
            [[maybe_unused]] std::size_t otherPin) final
        {};
    };

    class InputComponents : public AComponent {
    public:
        virtual void setState(nts::Tristate state) = 0;
    };

    // Special components
    class InputComponent : public InputComponents {
    private:
        nts::Tristate _state = nts::Undefined;
        nts::Tristate _oldState = nts::Undefined;

    public:
        void simulate(std::size_t tick) override;

        nts::Tristate compute(std::size_t pin) override;

        void setState(nts::Tristate state) override;
    };

    class OutputComponent : public AComponent {
    public:
        void simulate(std::size_t tick) override;

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

    class ClockComponent : public InputComponents {
    private:
        nts::Tristate _state = nts::Undefined;
        nts::Tristate _oldState = nts::Undefined;

    public:
        void simulate(std::size_t tick) override;

        nts::Tristate compute(std::size_t pin) override;

        void setState(nts::Tristate state) override;
    };
}

#endif //NANOTEKSPICE_SPECIAL_HPP
