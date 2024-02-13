/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Tristate
*/

#include <map>

#include "Tristate.hpp"

using namespace nts;

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

static const std::map<Tristate, char> _tristateCharacters = {
    {Undefined, 'U'},
    {False, '0'},
    {True, '1'}
};

std::ostream &operator<<(std::ostream &os, Tristate state)
{
    return os << _tristateCharacters.at(state);
}
