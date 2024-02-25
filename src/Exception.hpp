/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Exception
*/

#ifndef NANOTEKSPICE_EXCEPTION_HPP_
    #define NANOTEKSPICE_EXCEPTION_HPP_

    #include <exception>
    #include <string>

namespace nts {
    class Exception : std::exception {
        public:
            Exception()
                : _message(this->makeMessage())
            {};

            [[nodiscard]] const char *what() const noexcept final;

        protected:
            [[nodiscard]] virtual std::string makeMessage() const;

        private:
            const std::string _message;
    };
}

#endif /* !NANOTEKSPICE_EXCEPTION_HPP_ */
