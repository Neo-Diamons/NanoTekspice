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
        if (a == True || b == True)
            return True;
        return a == Undefined || b == Undefined ? Undefined : False;
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

    constexpr nts::Tristate toTristate(const std::string &str)
    {
        if (str == "0")
            return nts::Tristate::False;
        if (str == "1")
            return nts::Tristate::True;
        if (str == "U")
            return nts::Tristate::Undefined;
        throw std::invalid_argument("Invalid Tristate");
    }
}

#endif //NANOTEKSPICE_TRISTATE_HPP
