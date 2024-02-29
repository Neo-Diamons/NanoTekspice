/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** LinkMap
*/

#ifndef NANOTEKSPICE_LINKMAP_HPP_
    #define NANOTEKSPICE_LINKMAP_HPP_

    #include <map>

    #include "Link.hpp"

namespace nts {
    class LinkMap : private std::map<std::size_t, Link> {
        private:
            const IComponent * const _component;

        public:
            LinkMap(const IComponent *component)
                : _component(component)
            {}

            [[nodiscard]] Tristate compute(std::size_t pin) const;

            std::pair<iterator, bool> insert_or_assign(std::size_t pin, Link &&link);

            class LinkNotFoundException : public Exception {
                public:
                    LinkNotFoundException(std::size_t pin, const std::string &componentName)
                        : _pin(pin), _componentName(componentName)
                    {}

                    std::size_t getPin() const noexcept { return _pin; }
                    const std::string &getComponentName() const noexcept { return _componentName; }

                protected:
                    [[nodiscard]] std::string makeMessage() const noexcept final;

                private:
                    const std::size_t _pin;
                    const std::string _componentName;
            };
    };
}

#endif /* !NANOTEKSPICE_LINKMAP_HPP_ */
