/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IInputComponent
*/

#ifndef NANOTEKSPICE_IINPUTCOMPONENT_HPP_
    #define NANOTEKSPICE_IINPUTCOMPONENT_HPP_

    #include "IComponent.hpp"

namespace nts {
    class IInputComponent : public virtual IComponent {
        public:
            virtual ~IInputComponent() = default;

            virtual Tristate getState() = 0;
            virtual void setState(Tristate state) = 0;
    };
}

#endif /* !NANOTEKSPICE_IINPUTCOMPONENT_HPP_ */
