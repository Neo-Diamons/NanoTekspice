/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Parser
*/

#ifndef NANOTEKSPICE_PARSER_HPP
#define NANOTEKSPICE_PARSER_HPP

#include <fstream>

#include "Circuit.hpp"

namespace nts {
    class Parser {
    private:
        std::string _filename;
        std::ifstream _file;

        void parseChipsets(Circuit &circuit);
        void parseLinks(Circuit &circuit);

    public:
        explicit Parser(const std::string &filename);

        void parse(Circuit &circuit);
    };
}

#endif //NANOTEKSPICE_PARSER_HPP
