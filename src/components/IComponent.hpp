/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** IComponent
*/

#ifndef NANOTEKSPICE_ICOMPONENT_HPP
#define NANOTEKSPICE_ICOMPONENT_HPP

#include <map>

#include "src/Tristate.hpp"

namespace nts {
    class Link;

    class IComponent {
    public:
        virtual ~IComponent() = default;

        [[nodiscard]] virtual bool asInput(std::size_t pin) const = 0;
        [[nodiscard]] virtual bool asOutput(std::size_t pin) const = 0;
        [[nodiscard]] virtual std::map<std::size_t, Link> &getPins() = 0;

        virtual void simulate(std::size_t tick) = 0;
        virtual Tristate compute(std::size_t pin) = 0;
    };
}

#endif //NANOTEKSPICE_ICOMPONENT_HPP
