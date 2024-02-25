/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ClockComponent
*/

#ifndef NANOTEKSPICE_CLOCKCOMPONENT_HPP_
    #define NANOTEKSPICE_CLOCKCOMPONENT_HPP_

    #include "../../Circuit.hpp"

    #include "../AInputComponent.hpp"

namespace nts {
    class ClockComponent : public AInputComponent {
        public:
            static constexpr const char name[] = "clock";

            ClockComponent(const Circuit &circuit, const std::string &name)
                : AInputComponent(circuit, name), _lastUpdate(this->_circuit.getTick())
            {}

            Tristate compute([[maybe_unused]] std::size_t pin) final;

        private:
            std::size_t _lastUpdate;
    };
}

#endif /* !NANOTEKSPICE_CLOCKCOMPONENT_HPP_ */
