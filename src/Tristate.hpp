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
        Undefined = -true,
        True      = true,
        False     = false
    };

    // AND
    constexpr Tristate operator&&(const Tristate a, const Tristate b)
    {
        if (a == False || b == False)
            return False;
        return a == Undefined || b == Undefined ? Undefined : True;
    }

    // OR
    constexpr Tristate operator||(const Tristate a, const Tristate b)
    {
        if (a == True || b == True)
            return True;
        return a == Undefined || b == Undefined ? Undefined : False;
    }

    // NOT
    constexpr Tristate operator!(const Tristate a)
    {
        if (a == Undefined)
            return Undefined;
        return a == True ? False : True;
    }

    // NAND
    constexpr Tristate operator&(const Tristate a, const Tristate b)
    {
        return !(a && b);
    }

    // XOR
    constexpr Tristate operator^(const Tristate a, const Tristate b)
    {
        if (a == Undefined || b == Undefined)
            return Undefined;
        return a != b ? True : False;
    }

    // NOR
    constexpr Tristate operator|(const Tristate a, const Tristate b)
    {
        return !(a || b);
    }

    constexpr std::ostream &operator<<(std::ostream &os, const Tristate state)
    {
        switch (state) {
            case Undefined:
                os << "U";
                break;
            case True:
                os << "1";
                break;
            case False:
                os << "0";
                break;
        }

        return os;
    }

    constexpr Tristate toTristate(const std::string &str)
    {
        if (str == "0")
            return False;
        if (str == "1")
            return True;
        if (str == "U")
            return Undefined;
        throw std::invalid_argument("Invalid Tristate");
    }
}

#endif //NANOTEKSPICE_TRISTATE_HPP
