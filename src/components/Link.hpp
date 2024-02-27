/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Link
*/

#ifndef NANOTEKSPICE_LINK_HPP
#define NANOTEKSPICE_LINK_HPP

#include "IComponent.hpp"

namespace nts {
    class Link {
    private:
        std::shared_ptr<IComponent> _component;
        std::size_t _pin;

    public:
        Link();
        Link(const std::shared_ptr<IComponent> &component, std::size_t pin);

        void simulate(std::size_t tick);
        [[nodiscard]] nts::Tristate compute() const;
    };
}

#endif //NANOTEKSPICE_LINK_HPP
