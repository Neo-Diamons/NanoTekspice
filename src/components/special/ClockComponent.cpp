/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"

using namespace nts;

Tristate ClockComponent::compute([[maybe_unused]] std::size_t pin)
{
    Tristate state = this->_state;

    std::size_t tick = this->_circuit.getTick();
    if (tick != this->_lastUpdate) {
        this->_state = !state;
        this->_lastUpdate = tick;
    }

    return state;
}
