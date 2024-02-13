/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Tristate
*/

#ifndef NANOTEKSPICE_TRISTATE_HPP
    #define NANOTEKSPICE_TRISTATE_HPP

    #include <iostream>

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    constexpr Tristate operator&(Tristate a, Tristate b);
    constexpr Tristate operator^(Tristate a, Tristate b);
    constexpr Tristate operator|(Tristate a, Tristate b);

    constexpr Tristate operator!(Tristate a);

    std::ostream &operator<<(std::ostream &os, Tristate state);
}

#endif //NANOTEKSPICE_TRISTATE_HPP
