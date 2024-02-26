/*
** EPITECH PROJECT, 2024
** NanoTekSpice
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


    constexpr Tristate operator&(Tristate a, Tristate b)
    {
        if (a == False || b == False)
            return False;
        return a == Undefined || b == Undefined ? Undefined : True;
    }

    constexpr Tristate operator|(Tristate a, Tristate b)
    {
        if (a == True || b == True)
            return True;
        return a == Undefined || b == Undefined ? Undefined : False;
    }

    constexpr Tristate operator^(Tristate a, Tristate b)
    {
        if (a == Undefined || b == Undefined)
            return Undefined;
        return a != b ? True : False;
    }


    constexpr Tristate operator!(Tristate a)
    {
        if (a == Undefined)
            return Undefined;
        return a == True ? False : True;
    }


    std::ostream &operator<<(std::ostream &os, Tristate state);
}

#endif //NANOTEKSPICE_TRISTATE_HPP
