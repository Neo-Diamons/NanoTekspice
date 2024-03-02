/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Main
*/

#include "parsing/Shell.hpp"
#include "parsing/Parser.hpp"

int main(const int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " [filename]" << std::endl;
        return 84;
    }

    nts::Circuit circuit;
    nts::Parser parser(av[1]);
    parser.parse(circuit);
    nts::Shell::run(circuit);

    return 0;
}
