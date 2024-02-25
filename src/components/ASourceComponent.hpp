/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ASourceComponent
*/

#ifndef NANOTEKSPICE_ASOURCECOMPONENT_HPP_
    #define NANOTEKSPICE_ASOURCECOMPONENT_HPP_

    #include "AComponent.hpp"

namespace nts {
    class ASourceComponent : public AComponent {
        public:
            std::pair<const std::set<size_t> &, const std::set<size_t> &> getValidPins() final;

        protected:
            ASourceComponent(const Circuit &circuit, const std::string &name)
                : AComponent(circuit, name)
            {}

        private:
            static const std::pair<std::set<size_t>, std::set<size_t>> ioPins;
    };
}

#endif /* !NANOTEKSPICE_ASOURCECOMPONENT_HPP_ */
