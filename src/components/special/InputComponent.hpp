/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** InputComponent
*/

#ifndef NANOTEKSPICE_INPUTCOMPONENT_HPP_
    #define NANOTEKSPICE_INPUTCOMPONENT_HPP_

    #include "../AInputComponent.hpp"

namespace nts {
    class InputComponent : public AInputComponent {
        public:
            static constexpr const char typeName[] = "input";

            InputComponent(const Circuit &circuit, const std::string &name)
                : AInputComponent(circuit, name)
            {}

            Tristate compute([[maybe_unused]] std::size_t pin) final;
    };
}

#endif /* !NANOTEKSPICE_INPUTCOMPONENT_HPP_ */
