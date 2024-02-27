/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Parser
*/

#include "Parser.hpp"

#include <iostream>
#include <sstream>
#include <utility>
#include <csignal>

#include "Exception.hpp"

volatile bool isLoop = true;

void nts::Parser::signalHandler([[maybe_unused]] int signum)
{
    isLoop = false;
}

nts::Parser::Parser(std::string filename)
    : _filename(std::move(filename))
{}

void nts::Parser::parseChipsets()
{
    std::string line;
    std::string type;
    std::string value;

    while (std::getline(_file, line)) {
        if (line == ".links:")
            return;
        if (line.empty() || line[0] == '#')
            continue;

        std::istringstream iss(line);
        iss >> type >> value;
        try {
            _circuit.addComponent(type, value);
        } catch (const ExceptionUnknowComponent &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        } catch (const ExceptionDuplicateComponent &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        }
    }
}

void nts::Parser::parseLinks()
{
    std::string line;
    std::string comp1;
    std::string comp2;

    while (std::getline(_file, line)) {
        if (line.empty() || line[0] == '#')
            continue;

        std::istringstream iss(line);
        iss >> comp1 >> comp2;

        try {
            _circuit.addLink(
                comp1.substr(0, comp1.find(':')),
                std::stoi(comp1.substr(comp1.find(':') + 1)),
                comp2.substr(0, comp2.find(':')),
                std::stoi(comp2.substr(comp2.find(':') + 1))
            );
        } catch (const ExceptionUnknowComponent &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        } catch (const AComponent::ExceptionInvalidPin &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        }
    }
}

void nts::Parser::loop()
{
    std::string line;
    std::string value;

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line) || line == "exit")
            return;
        if (line == "display") {
            std::cout << _circuit;
            continue;
        }
        if (line == "simulate") {
            _circuit.simulate();
            continue;
        }
        if (line == "loop") {
            isLoop = true;
            while (isLoop) {
                signal(SIGINT, signalHandler);

                _circuit.simulate();
                std::cout << _circuit;
                usleep(100);
            }
        }

        std::istringstream iss(line);
        iss >> value;
        if (!_circuit.setValues(
            value.substr(0, value.find('=')),
            value.substr(value.find('=') + 1)
        ))
            std::cout << "Invalid input" << std::endl;
    }
}

void nts::Parser::parse()
{
    _file.open(_filename);
    if (!_file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        exit(84);
    }

    std::string line;
    while (std::getline(_file, line)) {
        if (line == ".chipsets:")
            break;
        if (line.empty() || line[0] == '#')
            continue;
        exit(84);
    }

    parseChipsets();
    parseLinks();

    _circuit.sortComponents();
    loop();

    _file.close();
}
