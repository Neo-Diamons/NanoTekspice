/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** AComponent
*/

#ifndef NANOTEKSPICE_ACOMPONENT_HPP
#define NANOTEKSPICE_ACOMPONENT_HPP

#include <string>
#include <list>

#include "IComponent.hpp"
#include "Link.hpp"

namespace nts {
    class AComponent : public IComponent {
    protected:
        std::map<std::size_t, Link> _pins{};
        std::size_t _lastTick = -1;
        std::list<std::size_t> _inputs;
        std::list<std::size_t> _outputs;

        Tristate checkPin(const std::string &name, std::size_t pin);

    public:
        [[nodiscard]] bool asInput(std::size_t pin) const override;
        [[nodiscard]] bool asOutput(std::size_t pin) const override;
        [[nodiscard]] std::map<std::size_t, Link> &getPins() override;

        void simulate(std::size_t tick) override;
    };
}

#endif //NANOTEKSPICE_ACOMPONENT_HPP
