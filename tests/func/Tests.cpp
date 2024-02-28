/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Tests
*/

#include <iostream>
#include <memory>

#include "src/parser/Factory.hpp"

int main()
{
    std::cout << "Hello, World!" << std::endl;

    auto gate = std::make_shared<nts::AndComponent>();
    auto input1 = std::make_shared<nts::FalseComponent>();
    auto input2 = std::make_shared<nts::TrueComponent>();
    auto inverter = std::make_shared<nts::NotComponent>();

    nts::Link::setLink(gate, 1, input1, 1);
    nts::Link::setLink(gate, 2, input2, 1);
    nts::Link::setLink(inverter, 1, gate, 3);

    std::cout << "!(" << input1->compute(1) << " && " << input2->compute(1) << ") -> " << inverter->compute(2) << std::endl;

    return EXIT_SUCCESS;
}
