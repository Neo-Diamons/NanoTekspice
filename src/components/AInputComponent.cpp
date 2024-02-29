/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AInputComponent
*/

#include "AInputComponent.hpp"

using namespace nts;

Tristate AInputComponent::getState() const noexcept
{
    return this->_state;
}

void AInputComponent::setState(Tristate state)
{
    this->_state = state;
}
