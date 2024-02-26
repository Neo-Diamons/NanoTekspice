/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** tests_4017
*/

#include <criterion/criterion.h>
#include <iostream>
#include "src/IComponent.hpp"

Test(gates4017, test00)
{
    nts::Gates4017 gate;

    auto in_0 = std::make_shared<nts::TrueComponent>();
    auto in_1 = std::make_shared<nts::TrueComponent>();
    auto in_r = std::make_shared<nts::FalseComponent>();

    gate.setLink(14, in_0, 1);
    gate.setLink(13, in_1, 1);
    gate.setLink(15, in_r, 1);

    cr_assert_eq(gate.compute(3), nts::True);
    cr_assert_eq(gate.compute(2), nts::False);
    cr_assert_eq(gate.compute(4), nts::False);
    cr_assert_eq(gate.compute(7), nts::False);
    cr_assert_eq(gate.compute(10), nts::False);
    cr_assert_eq(gate.compute(1), nts::False);
    cr_assert_eq(gate.compute(5), nts::False);
    cr_assert_eq(gate.compute(6), nts::False);
    cr_assert_eq(gate.compute(9), nts::False);

    gate.simulate(1);

    cr_assert_eq(gate.compute(3), nts::False);
    cr_assert_eq(gate.compute(2), nts::True);
    cr_assert_eq(gate.compute(4), nts::False);
    cr_assert_eq(gate.compute(7), nts::False);
    cr_assert_eq(gate.compute(10), nts::False);
    cr_assert_eq(gate.compute(1), nts::False);
    cr_assert_eq(gate.compute(5), nts::False);
    cr_assert_eq(gate.compute(6), nts::False);
    cr_assert_eq(gate.compute(9), nts::False);
    cr_assert_eq(gate.compute(11), nts::False);
    cr_assert_eq(gate.compute(12), nts::True);

    gate.simulate(1);
    gate.simulate(1);
    gate.simulate(1);
    gate.simulate(1);
    gate.simulate(1);
    gate.simulate(1);
    gate.simulate(1);
    gate.simulate(1);

    cr_assert_eq(gate.compute(3), nts::False);
    cr_assert_eq(gate.compute(2), nts::False);
    cr_assert_eq(gate.compute(4), nts::False);
    cr_assert_eq(gate.compute(7), nts::False);
    cr_assert_eq(gate.compute(10), nts::False);
    cr_assert_eq(gate.compute(1), nts::False);
    cr_assert_eq(gate.compute(5), nts::False);
    cr_assert_eq(gate.compute(6), nts::False);
    cr_assert_eq(gate.compute(9), nts::False);
    cr_assert_eq(gate.compute(11), nts::True);
    cr_assert_eq(gate.compute(12), nts::False);

    gate.simulate(1);

    cr_assert_eq(gate.compute(3), nts::True);
    cr_assert_eq(gate.compute(2), nts::False);
    cr_assert_eq(gate.compute(4), nts::False);
    cr_assert_eq(gate.compute(7), nts::False);
    cr_assert_eq(gate.compute(10), nts::False);
    cr_assert_eq(gate.compute(1), nts::False);
    cr_assert_eq(gate.compute(5), nts::False);
    cr_assert_eq(gate.compute(6), nts::False);
    cr_assert_eq(gate.compute(9), nts::False);
    cr_assert_eq(gate.compute(11), nts::False);
    cr_assert_eq(gate.compute(12), nts::True);
}

Test(gates4017, reset)
{
    nts::Gates4017 gate;

    auto in_0 = std::make_shared<nts::TrueComponent>();
    auto in_1 = std::make_shared<nts::TrueComponent>();
    auto in_r = std::make_shared<nts::InputComponent>();

    in_r->setState(nts::False);

    gate.setLink(14, in_0, 1);
    gate.setLink(13, in_1, 1);
    gate.setLink(15, in_r, 1);

    gate.simulate(1);
    gate.simulate(1);
    gate.simulate(1);

    cr_assert_eq(gate.compute(3), nts::False);
    cr_assert_eq(gate.compute(2), nts::False);
    cr_assert_eq(gate.compute(4), nts::False);
    cr_assert_eq(gate.compute(7), nts::True);
    cr_assert_eq(gate.compute(10), nts::False);
    cr_assert_eq(gate.compute(1), nts::False);
    cr_assert_eq(gate.compute(5), nts::False);
    cr_assert_eq(gate.compute(6), nts::False);
    cr_assert_eq(gate.compute(9), nts::False);
    cr_assert_eq(gate.compute(11), nts::False);
    cr_assert_eq(gate.compute(12), nts::True);

    in_r->setState(nts::True);
    gate.simulate(1);

    cr_assert_eq(gate.compute(3), nts::True);
    cr_assert_eq(gate.compute(2), nts::False);
    cr_assert_eq(gate.compute(4), nts::False);
    cr_assert_eq(gate.compute(7), nts::False);
    cr_assert_eq(gate.compute(10), nts::False);
    cr_assert_eq(gate.compute(1), nts::False);
    cr_assert_eq(gate.compute(5), nts::False);
    cr_assert_eq(gate.compute(6), nts::False);
    cr_assert_eq(gate.compute(9), nts::False);
    cr_assert_eq(gate.compute(11), nts::False);
    cr_assert_eq(gate.compute(12), nts::True);
}
