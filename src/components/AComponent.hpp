/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AComponent
*/

#ifndef NANOTEKSPICE_ACOMPONENT_HPP_
    #define NANOTEKSPICE_ACOMPONENT_HPP_

    #include <map>

    #include "IComponent.hpp"
    #include "LinkMap.hpp"

namespace nts {
    class Circuit;

    class AComponent : public virtual IComponent {
        public:
            const std::string &getName() const noexcept final;
            void setLink(std::size_t pin, IComponent *other, std::size_t otherPin) final;

        protected:
            AComponent(const Circuit &circuit, const std::string &name)
                : _circuit(circuit), _name(name)
            {}

            const Circuit &_circuit;
            const std::string _name;
            LinkMap _pins = LinkMap(this);
    };
}

#endif /* !NANOTEKSPICE_ACOMPONENT_HPP_ */
