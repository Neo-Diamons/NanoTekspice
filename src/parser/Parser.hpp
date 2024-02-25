/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Parser
*/

#ifndef NANOTEKSPICE_PARSER_HPP
#define NANOTEKSPICE_PARSER_HPP

#include <fstream>

#include "./Circuit.hpp"

class Parser {
private:
    std::string _filename;
    std::ifstream _file;
    Circuit _circuit;

    void parseChipsets();
    void parseLinks();
    void loop();

public:
    explicit Parser(std::string filename);

    bool parse();
};

#endif //NANOTEKSPICE_PARSER_HPP