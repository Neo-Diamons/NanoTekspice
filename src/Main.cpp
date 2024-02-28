/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Main
*/

#include <iostream>

#include "parser/Parser.hpp"

#include "parser/Factory.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " [filename]" << std::endl;
        return 84;
    }

    nts::Parser parser(av[1]);
    parser.parse();

//    auto gate = std::make_shared<nts::Gates4008>();
//
//    auto in_a1 = std::make_shared<nts::InputComponent>();
//    auto in_a2 = std::make_shared<nts::InputComponent>();
//    auto in_a3 = std::make_shared<nts::InputComponent>();
//    auto in_a4 = std::make_shared<nts::InputComponent>();
//    auto in_b1 = std::make_shared<nts::InputComponent>();
//    auto in_b2 = std::make_shared<nts::InputComponent>();
//    auto in_b3 = std::make_shared<nts::InputComponent>();
//    auto in_b4 = std::make_shared<nts::InputComponent>();
//    auto in_c = std::make_shared<nts::InputComponent>();
//
//    in_c->setState(nts::True);
//
//    in_a1->setState(nts::False);
//    in_b1->setState(nts::False);
//
//    in_a2->setState(nts::True);
//    in_b2->setState(nts::False);
//
//    in_a3->setState(nts::False);
//    in_b3->setState(nts::True);
//
//    in_a4->setState(nts::True);
//    in_b4->setState(nts::True);
//
//    nts::Link::setLink(gate, 9, in_c, 1);
//
//    nts::Link::setLink(gate, 7, in_a1, 1);
//    nts::Link::setLink(gate, 6, in_b1, 1);
//
//    nts::Link::setLink(gate, 5, in_a2, 1);
//    nts::Link::setLink(gate, 4, in_b2, 1);
//
//    nts::Link::setLink(gate, 3, in_a3, 1);
//    nts::Link::setLink(gate, 2, in_b3, 1);
//
//    nts::Link::setLink(gate, 1, in_a4, 1);
//    nts::Link::setLink(gate, 15, in_b4, 1);
//
//    gate->simulate(1);
//
//    std::cout << gate->compute(10) << std::endl;
//    std::cout << gate->compute(11) << std::endl;
//    std::cout << gate->compute(12) << std::endl;
//    std::cout << gate->compute(13) << std::endl;
//    std::cout << gate->compute(14) << std::endl;


//    cr_assert_eq(gate->compute(10), nts::False);
//    cr_assert_eq(gate->compute(11), nts::True);
//    cr_assert_eq(gate->compute(12), nts::True);
//    cr_assert_eq(gate->compute(13), nts::True);
//    cr_assert_eq(gate->compute(14), nts::False);

    return 0;
}
