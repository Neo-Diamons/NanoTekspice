/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Advanced
*/

#ifndef NANOTEKSPICE_ADVANCED_HPP
#define NANOTEKSPICE_ADVANCED_HPP

#include "../AComponent.hpp"

namespace nts {
    class Gates4008 : public AComponent {
    private:
        std::map<int, nts::Tristate> _outPins;

        nts::Tristate add(int idA, int idB, nts::Tristate carry);

    public:
        nts::Tristate compute(std::size_t pin) override;
    };

    class Gates4017 : public AComponent {
    private:
        std::size_t _count = 0;

    public:
        void simulate(std::size_t tick) override;

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
        void simulate(std::size_t tick) override;

        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif //NANOTEKSPICE_ADVANCED_HPP
