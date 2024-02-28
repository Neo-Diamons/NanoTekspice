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
    class AndComponent final : public AComponent {
    public:
        AndComponent() {
            _inputs = {1, 2};
            _outputs = {3};
        }

        Tristate compute(std::size_t pin) override;
    };

    class OrComponent final : public AComponent {
    public:
        OrComponent() {
            _inputs = {1, 2};
            _outputs = {3};
        }

        Tristate compute(std::size_t pin) override;
    };

    class XorComponent final : public AComponent {
    public:
        XorComponent() {
            _inputs = {1, 2};
            _outputs = {3};
        }

        Tristate compute(std::size_t pin) override;
    };

    class NotComponent final : public AComponent {
    public:
        NotComponent() {
            _inputs = {1};
            _outputs = {2};
        }

        Tristate compute(std::size_t pin) override;
    };
}

#endif //NANOTEKSPICE_ELEMENTARY_HPP
