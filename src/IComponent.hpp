/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IComponent
*/

#ifndef NANOTEKSPICE_ICOMPONENT_HPP
#define NANOTEKSPICE_ICOMPONENT_HPP

#include <memory>
#include <map>

#include "Tristate.hpp"
#include "components/AComponent.hpp"

namespace nts {
    // Elementary components
    class AndComponent : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class OrComponent : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class XorComponent : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class NotComponent : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    // Gates components
    class Gates4001 : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4011 : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4030 : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4069 : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4071 : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4081 : public AComponent {
    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    // Advanced components
    class Gates4008 : public AComponent {
    private:
        nts::Tristate add(int idA, int idB, nts::Tristate carry);

    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4017 : public AComponent {
    private:
        std::size_t _count = 0;

    public:

        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4013 : public AComponent {
    private:
        std::map<int, nts::Tristate> _outPins = {
            {1, nts::Undefined},
            {2, nts::Undefined},
            {3, nts::Undefined},
            {4, nts::Undefined},
        };

    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4040 : public AComponent {
    private:
        unsigned _count = 0;

    public:

        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif //NANOTEKSPICE_ICOMPONENT_HPP
