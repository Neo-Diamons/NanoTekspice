/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** tests_4040
*/

#include <criterion/criterion.h>
#include <iostream>
#include "src/IComponent.hpp"

Test(gates4040, test00)
{
    nts::Gates4040 gate;

    auto cl_clock = std::make_shared<nts::ClockComponent>();
    auto in_reset = std::make_shared<nts::FalseComponent>();

    gate.setLink(10, cl_clock, 1);
    gate.setLink(11, in_reset, 1);

    cr_assert_eq(gate.compute(9), nts::False);
    cr_assert_eq(gate.compute(7), nts::False);
    cr_assert_eq(gate.compute(6), nts::False);
    cr_assert_eq(gate.compute(5), nts::False);
    cr_assert_eq(gate.compute(3), nts::False);
    cr_assert_eq(gate.compute(2), nts::False);
    cr_assert_eq(gate.compute(4), nts::False);
    cr_assert_eq(gate.compute(13), nts::False);
    cr_assert_eq(gate.compute(12), nts::False);
    cr_assert_eq(gate.compute(14), nts::False);
    cr_assert_eq(gate.compute(15), nts::False);
    cr_assert_eq(gate.compute(1), nts::False);

    gate.simulate(2);

    cr_assert_eq(gate.compute(9), nts::True);
    cr_assert_eq(gate.compute(7), nts::False);
    cr_assert_eq(gate.compute(6), nts::False);
    cr_assert_eq(gate.compute(5), nts::False);
    cr_assert_eq(gate.compute(3), nts::False);
    cr_assert_eq(gate.compute(2), nts::False);
    cr_assert_eq(gate.compute(4), nts::False);
    cr_assert_eq(gate.compute(13), nts::False);
    cr_assert_eq(gate.compute(12), nts::False);
    cr_assert_eq(gate.compute(14), nts::False);
    cr_assert_eq(gate.compute(15), nts::False);
    cr_assert_eq(gate.compute(1), nts::False);

    gate.simulate(2);

    cr_assert_eq(gate.compute(9), nts::False);
    cr_assert_eq(gate.compute(7), nts::True);
    cr_assert_eq(gate.compute(6), nts::False);
    cr_assert_eq(gate.compute(5), nts::False);
    cr_assert_eq(gate.compute(3), nts::False);
    cr_assert_eq(gate.compute(2), nts::False);
    cr_assert_eq(gate.compute(4), nts::False);
    cr_assert_eq(gate.compute(13), nts::False);
    cr_assert_eq(gate.compute(12), nts::False);
    cr_assert_eq(gate.compute(14), nts::False);
    cr_assert_eq(gate.compute(15), nts::False);
    cr_assert_eq(gate.compute(1), nts::False);

    gate.simulate(2);

    cr_assert_eq(gate.compute(9), nts::True);
    cr_assert_eq(gate.compute(7), nts::True);
    cr_assert_eq(gate.compute(6), nts::False);
    cr_assert_eq(gate.compute(5), nts::False);
    cr_assert_eq(gate.compute(3), nts::False);
    cr_assert_eq(gate.compute(2), nts::False);
    cr_assert_eq(gate.compute(4), nts::False);
    cr_assert_eq(gate.compute(13), nts::False);
    cr_assert_eq(gate.compute(12), nts::False);
    cr_assert_eq(gate.compute(14), nts::False);
    cr_assert_eq(gate.compute(15), nts::False);
    cr_assert_eq(gate.compute(1), nts::False);

    for (int i = 0; i < 4093; i++)
        gate.simulate(2);

    cr_assert_eq(gate.compute(9), nts::False);
    cr_assert_eq(gate.compute(7), nts::False);
    cr_assert_eq(gate.compute(6), nts::False);
    cr_assert_eq(gate.compute(5), nts::False);
    cr_assert_eq(gate.compute(3), nts::False);
    cr_assert_eq(gate.compute(2), nts::False);
    cr_assert_eq(gate.compute(4), nts::False);
    cr_assert_eq(gate.compute(13), nts::False);
    cr_assert_eq(gate.compute(12), nts::False);
    cr_assert_eq(gate.compute(14), nts::False);
    cr_assert_eq(gate.compute(15), nts::False);
    cr_assert_eq(gate.compute(1), nts::False);
}
