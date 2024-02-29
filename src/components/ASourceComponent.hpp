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
            std::pair<const std::set<std::size_t> &, const std::set<std::size_t> &> getValidPins() const final;

        protected:
            ASourceComponent(const Circuit &circuit, const std::string &name)
                : AComponent(circuit, name)
            {}

        private:
            static const std::pair<std::set<std::size_t>, std::set<std::size_t>> ioPins;
    };
}

#endif /* !NANOTEKSPICE_ASOURCECOMPONENT_HPP_ */
