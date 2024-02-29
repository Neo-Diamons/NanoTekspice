/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** FalseComponent
*/

#ifndef NANOTEKSPICE_FALSECOMPONENT_HPP_
    #define NANOTEKSPICE_FALSECOMPONENT_HPP_

    #include "../ASourceComponent.hpp"

namespace nts {
    class FalseComponent : public ASourceComponent {
        public:
            static constexpr const char typeName[] = "false";

            FalseComponent(const Circuit &circuit, const std::string &name)
                : ASourceComponent(circuit, name)
            {}

            Tristate compute([[maybe_unused]] std::size_t pin) final;
    };
}

#endif /* !NANOTEKSPICE_FALSECOMPONENT_HPP_ */
