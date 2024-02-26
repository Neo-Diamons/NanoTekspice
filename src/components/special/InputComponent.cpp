/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** InputComponent
*/

#include "InputComponent.hpp"

using namespace nts;

Tristate InputComponent::compute([[maybe_unused]] std::size_t pin)
{
    return this->_state;
}
