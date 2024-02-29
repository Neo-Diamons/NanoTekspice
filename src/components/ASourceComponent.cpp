/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ASourceComponent
*/

#include "ASourceComponent.hpp"

using namespace nts;

const std::pair<std::set<std::size_t>, std::set<std::size_t>> ASourceComponent::ioPins = {{}, {1}};

std::pair<const std::set<std::size_t> &, const std::set<std::size_t> &> ASourceComponent::getValidPins() const
{
    return ioPins;
}
