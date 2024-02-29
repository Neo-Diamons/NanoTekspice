/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Circuit
*/

#ifndef NANOTEKSPICE_CIRCUIT_HPP_
    #define NANOTEKSPICE_CIRCUIT_HPP_

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
            std::list<std::unique_ptr<IComponent>> _components;
            std::list<std::pair<IInputComponent * const, Tristate>> _inputs;
            std::map<std::string, std::pair<std::size_t, Tristate>> _outputs;
            ssize_t _tick = -1;
            std::size_t _nextPin = 0;
            std::set<std::size_t> _iPins;

            static const std::set<std::size_t> oPins;

        public:
            Circuit() noexcept
                : AComponent(*this, "Circuit")
            {}

            [[nodiscard]] std::list<std::reference_wrapper<const std::string>> getNames() const;
            void addComponent(std::unique_ptr<IComponent> component);
            void addOutput(const std::string &name);
            void linkComponents(const std::string &in, std::size_t iPin, const std::string &out, std::size_t oPin);
            void display() const;
            void simulate();
            std::size_t getTick() const noexcept;
            std::pair<const std::set<std::size_t> &, const std::set<std::size_t> &> getValidPins() const final;

            Tristate compute(std::size_t pin) final;

            class ComponentNotFoundException : public Exception {
                public:
                    ComponentNotFoundException(const std::string &name)
                        : _name(name)
                    {}

                    const std::string &getName() const noexcept { return _name; }

                protected:
                    const std::string _name;
                    [[nodiscard]] std::string makeMessage() const noexcept final;
            };
    };
}

#endif /* !NANOTEKSPICE_CIRCUIT_HPP_ */
