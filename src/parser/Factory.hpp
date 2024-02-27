/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Factory
*/

#ifndef NANOTEKSPICE_FACTORY_HPP
#define NANOTEKSPICE_FACTORY_HPP

#include <string>
#include <tuple>
#include <utility>

#include "src/components/special/Special.hpp"
#include "src/components/elementary/Elementary.hpp"
#include "src/components/gates/Gates.hpp"
#include "src/components/advanced/Advanced.hpp"

namespace nts {
    class Factory {
    public:
        class ExceptionUnknowComponent : public std::exception {
        private:
            std::string type;

        public:
            explicit ExceptionUnknowComponent(std::string type)
                : type(std::move(type))
            {};

            [[nodiscard]] const char *what() const noexcept override
            {
                return ("Unknown component name \'" + type + "\'.").c_str();
            }
        };

        static std::shared_ptr<nts::IComponent> createComponent(const std::string &type);
    };
}

#endif //NANOTEKSPICE_FACTORY_HPP
