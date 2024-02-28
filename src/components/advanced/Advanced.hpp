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
    class Gates4008 final : public AComponent {
    private:
        std::map<u_int8_t, Tristate> _outPins;

        Tristate add(u_int8_t idA, u_int8_t idB, Tristate carry);

    public:
        Gates4008()
        {
            _inputs = {1, 2, 3, 4, 5, 6, 7, 9, 15};
            _outputs = {10, 11, 12, 13, 14};
        }

        Tristate compute(std::size_t pin) override;
    };

    class Gates4017 final : public AComponent {
    private:
        std::size_t _count = 0;

    public:
        Gates4017()
        {
            _inputs = {13, 14, 15};
            _outputs = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12};
        }

        void simulate(std::size_t tick) override;

        Tristate compute(std::size_t pin) override;
    };

    class Gates4013 final : public AComponent {
    private:
        std::map<int, Tristate> _outPins = {
            {1, Undefined},
            {2, Undefined},
            {13, Undefined},
            {12, Undefined},
        };

    public:
        Gates4013()
        {
            _inputs = {3, 4, 5, 6, 9, 8, 10, 11};
            _outputs = {1, 2, 12, 13};
        }

        void simulate(std::size_t tick) override;

        Tristate compute(std::size_t pin) override;
    };

    class Gates4040 : public AComponent {
    private:
        unsigned _count = 0;

    public:
        Gates4040()
        {
            _inputs = {10, 11};
            _outputs = {1, 2, 3, 4, 5, 6, 7, 9, 12, 13, 14, 15};
        }

        void simulate(std::size_t tick) override;

        Tristate compute(std::size_t pin) override;
    };
}

#endif //NANOTEKSPICE_ADVANCED_HPP
