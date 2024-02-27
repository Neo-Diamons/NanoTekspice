/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Factory
*/

#include "Factory.hpp"

std::shared_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type)
{
    // Special
    if (type == "input")
        return std::make_shared<nts::InputComponent>();
    if (type == "output")
        return std::make_shared<nts::OutputComponent>();
    if (type == "clock")
        return std::make_shared<nts::ClockComponent>();
    if (type == "true")
        return std::make_shared<nts::TrueComponent>();
    if (type == "false")
        return std::make_shared<nts::FalseComponent>();
    // Elementary
    if (type == "and")
        return std::make_shared<nts::AndComponent>();
    if (type == "not")
        return std::make_shared<nts::NotComponent>();
    if (type == "or")
        return std::make_shared<nts::OrComponent>();
    if (type == "xor")
        return std::make_shared<nts::XorComponent>();
    // Gates
    if (type == "4001")
        return std::make_shared<nts::Gates4001>();
    if (type == "4011")
        return std::make_shared<nts::Gates4011>();
    if (type == "4030")
        return std::make_shared<nts::Gates4030>();
    if (type == "4069")
        return std::make_shared<nts::Gates4069>();
    if (type == "4071")
        return std::make_shared<nts::Gates4071>();
    if (type == "4081")
        return std::make_shared<nts::Gates4081>();
    // Advanced
    if (type == "4008")
        return std::make_shared<nts::Gates4008>();
    if (type == "4013")
        return std::make_shared<nts::Gates4013>();
    if (type == "4017")
        return std::make_shared<nts::Gates4017>();
    if (type == "4040")
        return std::make_shared<nts::Gates4040>();
    throw Factory::ExceptionUnknowComponent(type);
}
