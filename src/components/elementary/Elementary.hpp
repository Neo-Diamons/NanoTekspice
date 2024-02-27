/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Elementary
*/

#ifndef NANOTEKSPICE_ELEMENTARY_HPP
#define NANOTEKSPICE_ELEMENTARY_HPP

#include "../AComponent.hpp"

namespace nts {
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
}

#endif //NANOTEKSPICE_ELEMENTARY_HPP
