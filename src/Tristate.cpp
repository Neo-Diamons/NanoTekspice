/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Tristate
*/

#include <map>

#include "Tristate.hpp"

using namespace nts;

static const std::map<Tristate, char> _tristateCharacters = {
    {Undefined, 'U'},
    {False, '0'},
    {True, '1'}
};

std::ostream &nts::operator<<(std::ostream &os, Tristate state)
{
    return os << _tristateCharacters.at(state);
}
