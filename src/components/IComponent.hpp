/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IComponent
*/

#ifndef NANOTEKSPICE_ICOMPONENT_HPP_
    #define NANOTEKSPICE_ICOMPONENT_HPP_

    #include <memory>
    #include <set>
    #include <string>
    #include <utility>

    #include "../Tristate.hpp"

namespace nts {
    class IComponent {
        public:
            virtual ~IComponent() = default;

            virtual const std::string &getName() = 0;
            virtual Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, std::shared_ptr<IComponent> other, std::size_t otherPin) = 0;
            virtual std::pair<const std::set<std::size_t>&, const std::set<std::size_t>&> getValidPins() = 0;
    };
}


#endif /* !NANOTEKSPICE_ICOMPONENT_HPP_ */
