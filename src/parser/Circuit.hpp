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

#include "src/components/AComponent.hpp"

typedef std::list<std::shared_ptr<std::tuple<std::string, std::shared_ptr<nts::IComponent>>>> Components;

namespace nts {
    class Circuit {
    private:
        std::size_t _tick = 0;
        Components _components{};
        Components _inputs{};
        Components _outputs{};

    public:
        void addComponent(const std::string &type, const std::string &value);
        void sortComponents();

        void simulate();
        void addLink(const std::string &comp1, std::size_t pin1, const std::string &comp2, std::size_t pin2) const;
        bool setValues(const std::string &name, const std::string &value) const;

        [[nodiscard]] std::size_t getTick() const;
        [[nodiscard]] const Components &getInputs() const;
        [[nodiscard]] const Components &getOutputs() const;

        friend std::ostream &operator<<(std::ostream &os, const Circuit &circuit);
    };

    std::ostream &operator<<(std::ostream &os, const Circuit &circuit);
}

#endif //NANOTEKSPICE_CIRCUIT_HPP
