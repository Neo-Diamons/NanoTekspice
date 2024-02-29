/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Tristate
*/

#include <algorithm>
#include <list>

#include "Tristate.hpp"

using namespace nts;

static const std::list<std::pair<Tristate, const char * const>> _tristateCharacters = {
    {Undefined, "U"},
    {False, "0"},
    {True, "1"}
};

std::ostream &nts::operator<<(std::ostream &os, Tristate state)
{
    auto it = std::find_if(_tristateCharacters.begin(), _tristateCharacters.end(),
        [state](const auto &pair) {
            return pair.first == state;
        });
    if (it == _tristateCharacters.end())
        return os << _tristateCharacters.front().second;
    return os << it->second;
}

void nts::operator>>(const std::string &str, Tristate &state)
{
    auto it = std::find_if(_tristateCharacters.begin(), _tristateCharacters.end(),
        [str](const auto &pair) {
            return pair.second == str;
        });
    if (it == _tristateCharacters.end())
        throw InvalidTristateException(str);
    state = it->first;
}

[[nodiscard]] std::string InvalidTristateException::makeMessage() const noexcept
{
    return "Tristate::InvalidTristateException: '" + _string + "' is not a valid tristate";
}
