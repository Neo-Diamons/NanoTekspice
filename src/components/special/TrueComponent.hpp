/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** TrueComponent
*/

#ifndef NANOTEKSPICE_TRUECOMPONENT_HPP_
    #define NANOTEKSPICE_TRUECOMPONENT_HPP_

    #include "../ASourceComponent.hpp"

namespace nts {
    class TrueComponent : public ASourceComponent {
        public:
            static constexpr const char name[] = "true";

            TrueComponent(const Circuit &circuit, const std::string &name)
                : ASourceComponent(circuit, name)
            {}

            Tristate compute([[maybe_unused]] std::size_t pin) final;
    };
}

#endif /* !NANOTEKSPICE_TRUECOMPONENT_HPP_ */
