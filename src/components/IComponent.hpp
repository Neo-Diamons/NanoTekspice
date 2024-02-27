/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** IComponent
*/

#ifndef NANOTEKSPICE_ICOMPONENT_HPP
#define NANOTEKSPICE_ICOMPONENT_HPP

#include <memory>

#include "../Tristate.hpp"

namespace nts {
    class IComponent {
    public:
        virtual ~IComponent() = default;

        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, std::shared_ptr<IComponent> other, std::size_t otherPin) = 0;
    };
}

#endif //NANOTEKSPICE_ICOMPONENT_HPP
