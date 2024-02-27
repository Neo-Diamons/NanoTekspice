/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Main
*/

#include <iostream>

#include "parser/Parser.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " [filename]" << std::endl;
        return 84;
    }

    Parser parser(av[1]);
    parser.parse();

    return 0;
}
