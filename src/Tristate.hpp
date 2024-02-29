/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Tristate
*/

#ifndef NANOTEKSPICE_TRISTATE_HPP_
    #define NANOTEKSPICE_TRISTATE_HPP_

    #include <iostream>

    #include "Exception.hpp"

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };


    constexpr Tristate operator&(Tristate a, Tristate b) noexcept
    {
        if (a == False || b == False)
            return False;
        return a == Undefined || b == Undefined ? Undefined : True;
    }

    constexpr Tristate operator|(Tristate a, Tristate b) noexcept
    {
        if (a == True || b == True)
            return True;
        return a == Undefined || b == Undefined ? Undefined : False;
    }

    constexpr Tristate operator^(Tristate a, Tristate b) noexcept
    {
        if (a == Undefined || b == Undefined)
            return Undefined;
        return a != b ? True : False;
    }


    constexpr Tristate operator!(Tristate a) noexcept
    {
        if (a == Undefined)
            return Undefined;
        return a == True ? False : True;
    }


    std::ostream &operator<<(std::ostream &os, Tristate state);

    void operator>>(const std::string &str, Tristate &state);

    class InvalidTristateException : public Exception {
        public:
            InvalidTristateException(const std::string &string)
                : _string(string)
            {}

        protected:
            [[nodiscard]] std::string makeMessage() const noexcept final;

        private:
            const std::string _string;
    };
}

#endif /* !NANOTEKSPICE_TRISTATE_HPP_ */
