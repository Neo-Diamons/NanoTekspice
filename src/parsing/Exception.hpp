/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Execption
*/

#ifndef NANOTEKSPICE_EXECPTION_HPP
#define NANOTEKSPICE_EXECPTION_HPP

#include <exception>
#include <string>

namespace nts {
    class ExceptionInvalidPin final : public std::exception {
    private:
        std::string _message;

    public:
        explicit ExceptionInvalidPin(const std::string &message)
            : _message(message)
        {}

        [[nodiscard]] const char *what() const noexcept override
        {
            return _message.c_str();
        }
    };

    class ExceptionUnknowComponent final : public std::exception {
    private:
        std::string _type;

    public:
        explicit ExceptionUnknowComponent(const std::string &type)
            : _type("Unknown component name \'" + type + "\'.")
        {}

        [[nodiscard]] const char *what() const noexcept override
        {
            return _type.c_str();
        }
    };

    class ExceptionDuplicateComponent final : public std::exception {
    private:
        std::string _type;

    public:
        explicit ExceptionDuplicateComponent(const std::string &type)
            : _type("Duplicate component name \'" + type + "\'.")
        {}

        [[nodiscard]] const char *what() const noexcept override
        {
            return _type.c_str();
        }
    };
}

#endif //NANOTEKSPICE_EXECPTION_HPP
