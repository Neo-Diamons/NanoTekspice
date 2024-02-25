/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** FalseComponent
*/

#include "FalseComponent.hpp"

using namespace nts;

Tristate FalseComponent::compute([[maybe_unused]] std::size_t pin)
{
    return Tristate::False;
}
