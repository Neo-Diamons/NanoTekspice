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

#include "src/components/special/Special.hpp"
#include "src/components/elementary/Elementary.hpp"
#include "src/components/gates/Gates.hpp"
#include "src/components/advanced/Advanced.hpp"

class Factory {
public:
    class Exception : public std::exception {
    private:
        std::string _message;

    public:
        explicit Exception(const std::string &message)
            : _message("Factory: " + message)
        {};

        [[nodiscard]] const char *what() const noexcept override
        {
            return _message.c_str();
        }
    };

    static std::shared_ptr<nts::IComponent> createComponent(const std::string &type);
    static nts::Tristate stringToTristate(const std::string &str);
};

#endif //NANOTEKSPICE_FACTORY_HPP
