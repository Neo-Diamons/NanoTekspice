/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Shell
*/

#ifndef SHELL_HPP
#define SHELL_HPP

#include "Circuit.hpp"

namespace nts {
    class Shell {
    private:
        static void signalHandler(int signum);

    public:
        static void run(Circuit &circuit);
    };

}

#endif //SHELL_HPP
