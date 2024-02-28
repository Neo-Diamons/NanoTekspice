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

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "Exception.hpp"

volatile bool isLoop = true;

void nts::Parser::signalHandler([[maybe_unused]] int signum)
{
    isLoop = false;
}

nts::Parser::Parser(const std::string &filename)
    : _filename(filename)
{}

void nts::Parser::parseChipsets()
{
    std::string line;
    std::string type;
    std::string value;
    std::string garbage;

    while (std::getline(_file, line)) {
        if (line.starts_with(".links:"))
            return;
        line = line.substr(0, line.find('#'));
        if (line.empty())
            continue;

        std::istringstream iss(line);
        if (iss.fail())
            exit(84);
        iss >> type >> value;
        if (iss.fail() || iss >> garbage)
            exit(84);

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
    std::string garbage;

    while (std::getline(_file, line)) {
        line = line.substr(0, line.find('#'));
        if (line.empty())
            continue;

        std::istringstream iss(line);
        if (iss.fail())
            exit(84);
        iss >> comp1 >> comp2;
        if (iss.fail() || iss >> garbage)
            exit(84);

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
        } catch (const ExceptionInvalidPin &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        } catch (const std::invalid_argument &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        }
    }
}

void nts::Parser::loop()
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
        if (iss.fail()) {
            std::cout << "Invalid input" << std::endl;
            continue;
        }
        if (iss >> garbage) {
            std::cout << "Invalid input" << std::endl;
            continue;
        }

        if (input == "exit")
            return;
        if (input == "display") {
            std::cout << _circuit;
            continue;
        }
        if (input == "simulate") {
            _circuit.simulate();
            continue;
        }
        if (input == "loop") {
            isLoop = true;
            while (isLoop) {
                signal(SIGINT, signalHandler);

                _circuit.simulate();
                std::cout << _circuit;
                usleep(100);
            }
            continue;
        }

        try {
            _circuit.setValue(
                input.substr(0, input.find('=')),
                input.substr(input.find('=') + 1)
            );
        } catch (const std::invalid_argument &e) {
            std::cout << "Invalid input" << std::endl;
        }
    }
}

void nts::Parser::parse()
{
    struct stat st{};
    if (stat(_filename.c_str(), &st) == -1 || st.st_size == 0 || !S_ISREG(st.st_mode)
        || access(_filename.c_str(), F_OK | R_OK) == -1) {
        std::cerr << "Error: could not open file" << std::endl;
        exit(84);
    }
    _file.open(_filename);
    if (!_file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        exit(84);
    }

    std::string line;
    std::string garbage;

    while (std::getline(_file, line)) {
        if (line.starts_with(".chipsets:"))
            break;
        line = line.substr(0, line.find('#'));
        std::istringstream iss(line);
        if (iss.fail() || iss >> garbage)
            exit(84);
    }

    parseChipsets();
    parseLinks();

    _circuit.sortComponents();
    loop();

    _file.close();
}
