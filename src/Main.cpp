/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Main
*/

#include <iostream>
#include <memory>

#include "IComponent.hpp"

int main()
{
    std::cout << "Hello, World!" << std::endl;

    std::shared_ptr<nts::IComponent> gate = std::make_shared<nts::AndComponent>();
    std::shared_ptr<nts::IComponent> input1 = std::make_shared<nts::FalseComponent>();
    std::shared_ptr<nts::IComponent> input2 = std::make_shared<nts::TrueComponent>();
    std::shared_ptr<nts::IComponent> inverter = std::make_shared<nts::NotComponent>();

    gate->setLink(1, input1, 1);
    gate->setLink(2, input2, 1);
    inverter->setLink(1, gate, 3);
    std::cout << "!(" << input1->compute(1) << " && " << input2->compute(1)
        << ") -> " << inverter->compute(2) << std::endl;

    return 0;
}
