/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Main
*/

#include <iostream>

#include "parser/Parser.hpp"

#include "parser/Factory.hpp"

int main(const int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " [filename]" << std::endl;
        return 84;
    }

    nts::Parser parser(av[1]);
    parser.parse();

    return 0;
}
