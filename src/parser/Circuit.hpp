/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Circuit
*/

#ifndef NANOTEKSPICE_CIRCUIT_HPP
#define NANOTEKSPICE_CIRCUIT_HPP

#include <tuple>
#include <list>

#include "src/IComponent.hpp"

class Circuit {
private:
    std::size_t _tick = 0;
    std::list<std::shared_ptr<std::tuple<std::string, std::shared_ptr<nts::IComponent>>>> _components{};
    std::list<std::shared_ptr<std::tuple<std::string, std::shared_ptr<nts::IComponent>>>> _inputs{};
    std::list<std::shared_ptr<std::tuple<std::string, std::shared_ptr<nts::IComponent>>>> _outputs{};

public:
    bool addComponent(const std::string &type, const std::string &value);
    void sortComponents();

    void simulate();
    bool addLink(const std::string &comp1, std::size_t pin1, const std::string &comp2, std::size_t pin2);
    bool setValues(const std::string &name, const std::string &value);

    friend std::ostream &operator<<(std::ostream &os, const Circuit &circuit);
};

#endif //NANOTEKSPICE_CIRCUIT_HPP
