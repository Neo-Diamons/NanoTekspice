/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AInputComponent
*/

#ifndef NANOTEKSPICE_AINPUTCOMPONENT_HPP_
    #define NANOTEKSPICE_AINPUTCOMPONENT_HPP_

    #include "ASourceComponent.hpp"
    #include "IInputComponent.hpp"

namespace nts {
    class AInputComponent : public ASourceComponent, public IInputComponent {
        public:
            Tristate getState() final;
            void setState(Tristate state) final;

        protected:
            AInputComponent(const Circuit &circuit, const std::string &name)
                : ASourceComponent(circuit, name), _state(Undefined)
            {}

            Tristate _state;
    };
}

#endif /* !NANOTEKSPICE_AINPUTCOMPONENT_HPP_ */
