/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Circuit
*/

#ifndef NANOTEKSPICE_CIRCUIT_HPP
    #define NANOTEKSPICE_CIRCUIT_HPP

    #include <iostream>
    #include <list>
    #include <map>
    #include <memory>
    #include <ostream>
    #include <string>
    #include <utility>

    #include "Tristate.hpp"
    #include "Exception.hpp"
    #include "components/AComponent.hpp"
    #include "components/IInputComponent.hpp"

namespace nts {
    class Circuit : public AComponent {
        private:
            std::ostream &_os;
            std::list<std::unique_ptr<IComponent>> _components;
            std::list<std::pair<IInputComponent *, Tristate>> _inputs;
            std::map<std::string, std::pair<std::size_t, Tristate>> _outputs;
            std::size_t _tick = 0;
            std::size_t _nextPin = 0;
            static const std::set<std::size_t> oPins;
            std::set<std::size_t> _iPins;

        public:
            Circuit(std::ostream &os = std::cout)
                : AComponent(*this, "Circuit"), _os(os)
            {}

            [[nodiscard]] std::list<std::reference_wrapper<const std::string>> getNames() const;
            void addComponent(std::unique_ptr<IComponent> component);
            void addOutput(const std::string &name);
            void linkComponents(const std::string &in, std::size_t iPin, const std::string &out, std::size_t oPin);
            void display();
            void simulate();
            std::size_t getTick() const;
            std::pair<const std::set<std::size_t>&, const std::set<std::size_t>&> getValidPins() final;

            Tristate compute(std::size_t pin) final;

            class ComponentNotFoundException : public Exception {
                public:
                    ComponentNotFoundException(const std::string &name)
                        : _name(name)
                    {}

                    const std::string &getName() const { return _name; }

                protected:
                    const std::string _name;
                    [[nodiscard]] std::string makeMessage() const final;
            };
    };
}

#endif //NANOTEKSPICE_CIRCUIT_HPP
