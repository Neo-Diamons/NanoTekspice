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
    class Gates4001 final : public AComponent {
    public:
        Gates4001() : AComponent({1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11})
        {}

        Tristate compute(std::size_t pin) override;
    };

    class Gates4011 final : public AComponent {
    public:
        Gates4011() : AComponent({1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11})
        {}

        Tristate compute(std::size_t pin) override;
    };

    class Gates4030 final : public AComponent {
    public:
        Gates4030() : AComponent({1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11})
        {}

        Tristate compute(std::size_t pin) override;
    };

    class Gates4069 final : public AComponent {
    public:
        Gates4069() : AComponent({1, 3, 5, 9, 11, 13}, {2, 4, 6, 8, 10, 12})
        {}

        Tristate compute(std::size_t pin) override;
    };

    class Gates4071 final : public AComponent {
    public:
        Gates4071() : AComponent({1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11})
        {}

        Tristate compute(std::size_t pin) override;
    };

    class Gates4081 final : public AComponent {
    public:
        Gates4081() : AComponent({1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11})
        {}

        Tristate compute(std::size_t pin) override;
    };
}

#endif //NANOTEKSPICE_GATES_HPP
