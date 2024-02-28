/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Link
*/

#ifndef NANOTEKSPICE_LINK_HPP
#define NANOTEKSPICE_LINK_HPP

#include <memory>

#include "IComponent.hpp"

namespace nts {
    class Link {
    private:
        std::shared_ptr<IComponent> _component;

    public:
        Link();
        std::size_t _pin;
        Link(const std::shared_ptr<IComponent> &component, std::size_t pin);

        void simulate(std::size_t tick) const;
        [[nodiscard]] Tristate compute() const;

        static void setLink(const std::shared_ptr<IComponent>& component, std::size_t pin, const std::shared_ptr<IComponent>& toComponent, std::size_t toPin);
    };
}

#endif //NANOTEKSPICE_LINK_HPP
