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
        InputComponent()
        {
            _inputs = {};
            _outputs = {1};
        }

        void simulate(std::size_t tick) override;

        nts::Tristate compute(std::size_t pin) override;

        void setState(nts::Tristate state) override;
    };

    class OutputComponent : public AComponent {
    public:
        OutputComponent()
        {
            _inputs = {1};
            _outputs = {};
        }

        void simulate(std::size_t tick) override;

        nts::Tristate compute(std::size_t pin) override;
    };

    class TrueComponent : public ValueComponent {
    public:
        TrueComponent()
        {
            _inputs = {};
            _outputs = {1};
        }

        nts::Tristate compute(std::size_t pin) override;
    };

    class FalseComponent : public ValueComponent {
    public:
        FalseComponent()
        {
            _inputs = {};
            _outputs = {1};
        }

        nts::Tristate compute(std::size_t pin) override;
    };

    class ClockComponent : public InputComponents {
    private:
        nts::Tristate _state = nts::Undefined;
        nts::Tristate _oldState = nts::Undefined;

    public:
        ClockComponent()
        {
            _inputs = {};
            _outputs = {1};
        }

        void simulate(std::size_t tick) override;

        nts::Tristate compute(std::size_t pin) override;

        void setState(nts::Tristate state) override;
    };
}

#endif //NANOTEKSPICE_SPECIAL_HPP
