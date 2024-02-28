/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Factory
*/

#ifndef NANOTEKSPICE_FACTORY_HPP
#define NANOTEKSPICE_FACTORY_HPP

#include <string>

#include "src/components/special/Special.hpp"
#include "src/components/elementary/Elementary.hpp"
#include "src/components/gates/Gates.hpp"
#include "src/components/advanced/Advanced.hpp"

namespace nts {
    class Factory {
    public:
        static std::shared_ptr<IComponent> createComponent(const std::string &type);
    };
}

#endif //NANOTEKSPICE_FACTORY_HPP
