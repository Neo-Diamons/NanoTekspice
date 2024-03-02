/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Shell
*/

#include "Shell.hpp"

#include <sstream>
#include <csignal>

volatile bool isLoop = true;

void nts::Shell::signalHandler([[maybe_unused]] int signum)
{
    isLoop = false;
}

void nts::Shell::run(Circuit &circuit)
{
    std::string line;
    std::string input;
    std::string garbage;

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line))
            return;

        std::istringstream iss(line);
        if (iss.fail())
            exit(84);
        iss >> input;
        if (iss.fail() || iss >> garbage) {
            std::cout << "Invalid input" << std::endl;
            continue;
        }

        if (input == "exit")
            return;
        if (input == "display") {
            try {
                std::cout << circuit;
            } catch (const std::exception &e) {
                std::cout << e.what() << std::endl;
                exit(64);
            }
            continue;
        }
        if (input == "simulate") {
            circuit.simulate();
            continue;
        }
        if (input == "loop") {
            isLoop = true;
            while (isLoop) {
                signal(SIGINT, signalHandler);

                circuit.simulate();
                try {
                    std::cout << circuit;
                } catch (const std::exception &e) {
                    std::cout << e.what() << std::endl;
                    exit(64);
                }
            }
            continue;
        }

        try {
            circuit.setValue(
                input.substr(0, input.find('=')),
                input.substr(input.find('=') + 1)
            );
        } catch (const std::invalid_argument &e) {
            std::cout << "Invalid input" << std::endl;
        }
    }
}
