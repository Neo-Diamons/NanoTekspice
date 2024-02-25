/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Tristate
*/

#ifndef NANOTEKSPICE_TRISTATE_HPP
#define NANOTEKSPICE_TRISTATE_HPP

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True      = true,
        False     = false
    };

    constexpr Tristate operator&&(Tristate a, Tristate b)
    {
        if (a == False || b == False)
            return False;
        return a == Undefined || b == Undefined ? Undefined : True;
    }

    constexpr Tristate operator||(Tristate a, Tristate b)
    {
        return a == True || b == True ? True : False;
    }

    constexpr Tristate operator!(Tristate a)
    {
        if (a == Undefined)
            return Undefined;
        return a == True ? False : True;
    }

    constexpr Tristate operator&(Tristate a, Tristate b)
    {
        return !(a && b);
    }

    constexpr Tristate operator^(Tristate a, Tristate b)
    {
        if (a == Undefined || b == Undefined)
            return Undefined;
        return a != b ? True : False;
    }

    constexpr Tristate operator|(Tristate a, Tristate b)
    {
        return !(a || b);
    }

    constexpr std::ostream &operator<<(std::ostream &os, Tristate state)
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
}

#endif //NANOTEKSPICE_TRISTATE_HPP
