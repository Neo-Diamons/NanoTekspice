/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ASourceComponent
*/

#include "ASourceComponent.hpp"

using namespace nts;

const std::pair<std::set<size_t>, std::set<size_t>> ASourceComponent::ioPins = {{}, {1}};

std::pair<const std::set<size_t> &, const std::set<size_t> &> ASourceComponent::getValidPins()
{
    return ioPins;
}
