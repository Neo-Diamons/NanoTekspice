/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AComponent
*/

#ifndef NANOTEKSPICE_ACOMPONENT_HPP_
    #define NANOTEKSPICE_ACOMPONENT_HPP_

    #include <cstddef>
    #include <map>

    #include "IComponent.hpp"
    #include "Link.hpp"

namespace nts {
    class Circuit;

    class AComponent : public virtual IComponent {
        public:
            const std::string &getName() final;
            void setLink(std::size_t pin, std::shared_ptr<IComponent> other, std::size_t otherPin) final;

        protected:
            AComponent(const Circuit &circuit, const std::string &name)
                : _circuit(circuit), _name(name)
            {}

            const Circuit &_circuit;
            const std::string _name;
            std::map<size_t, Link> _pins{};
    };
}

#endif /* !NANOTEKSPICE_ACOMPONENT_HPP_ */
