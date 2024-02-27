/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Gates
*/

#ifndef NANOTEKSPICE_GATES_HPP
#define NANOTEKSPICE_GATES_HPP

#include "../AComponent.hpp"

namespace nts {
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
}

#endif //NANOTEKSPICE_GATES_HPP
