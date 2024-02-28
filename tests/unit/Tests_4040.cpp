/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** tests_4040
*/

#include <criterion/criterion.h>
#include <iostream>

#include "src/parser/Factory.hpp"

Test(gates4040, test00)
{
    auto gate = std::make_shared<nts::Gates4040>();

    auto cl_clock = std::make_shared<nts::ClockComponent>();
    auto in_reset = std::make_shared<nts::FalseComponent>();

    std::size_t tick = 0;

    nts::Link::setLink(gate, 10, cl_clock, 1);
    nts::Link::setLink(gate, 11, in_reset, 1);

    cr_assert_eq(gate->compute(9), nts::False);
    cr_assert_eq(gate->compute(7), nts::False);
    cr_assert_eq(gate->compute(6), nts::False);
    cr_assert_eq(gate->compute(5), nts::False);
    cr_assert_eq(gate->compute(3), nts::False);
    cr_assert_eq(gate->compute(2), nts::False);
    cr_assert_eq(gate->compute(4), nts::False);
    cr_assert_eq(gate->compute(13), nts::False);
    cr_assert_eq(gate->compute(12), nts::False);
    cr_assert_eq(gate->compute(14), nts::False);
    cr_assert_eq(gate->compute(15), nts::False);
    cr_assert_eq(gate->compute(1), nts::False);

    gate->simulate(tick++);
    gate->simulate(tick++);
    gate->simulate(tick++);

    cr_assert_eq(gate->compute(9), nts::True);
    cr_assert_eq(gate->compute(7), nts::False);
    cr_assert_eq(gate->compute(6), nts::False);
    cr_assert_eq(gate->compute(5), nts::False);
    cr_assert_eq(gate->compute(3), nts::False);
    cr_assert_eq(gate->compute(2), nts::False);
    cr_assert_eq(gate->compute(4), nts::False);
    cr_assert_eq(gate->compute(13), nts::False);
    cr_assert_eq(gate->compute(12), nts::False);
    cr_assert_eq(gate->compute(14), nts::False);
    cr_assert_eq(gate->compute(15), nts::False);
    cr_assert_eq(gate->compute(1), nts::False);

    gate->simulate(tick++);
    gate->simulate(tick++);

    cr_assert_eq(gate->compute(9), nts::False);
    cr_assert_eq(gate->compute(7), nts::True);
    cr_assert_eq(gate->compute(6), nts::False);
    cr_assert_eq(gate->compute(5), nts::False);
    cr_assert_eq(gate->compute(3), nts::False);
    cr_assert_eq(gate->compute(2), nts::False);
    cr_assert_eq(gate->compute(4), nts::False);
    cr_assert_eq(gate->compute(13), nts::False);
    cr_assert_eq(gate->compute(12), nts::False);
    cr_assert_eq(gate->compute(14), nts::False);
    cr_assert_eq(gate->compute(15), nts::False);
    cr_assert_eq(gate->compute(1), nts::False);

    gate->simulate(tick++);
    gate->simulate(tick++);

    cr_assert_eq(gate->compute(9), nts::True);
    cr_assert_eq(gate->compute(7), nts::True);
    cr_assert_eq(gate->compute(6), nts::False);
    cr_assert_eq(gate->compute(5), nts::False);
    cr_assert_eq(gate->compute(3), nts::False);
    cr_assert_eq(gate->compute(2), nts::False);
    cr_assert_eq(gate->compute(4), nts::False);
    cr_assert_eq(gate->compute(13), nts::False);
    cr_assert_eq(gate->compute(12), nts::False);
    cr_assert_eq(gate->compute(14), nts::False);
    cr_assert_eq(gate->compute(15), nts::False);
    cr_assert_eq(gate->compute(1), nts::False);

    for (int i = 0; i < 4093; i++) {
        gate->simulate(tick++);
        gate->simulate(tick++);
    }

    cr_assert_eq(gate->compute(9), nts::False);
    cr_assert_eq(gate->compute(7), nts::False);
    cr_assert_eq(gate->compute(6), nts::False);
    cr_assert_eq(gate->compute(5), nts::False);
    cr_assert_eq(gate->compute(3), nts::False);
    cr_assert_eq(gate->compute(2), nts::False);
    cr_assert_eq(gate->compute(4), nts::False);
    cr_assert_eq(gate->compute(13), nts::False);
    cr_assert_eq(gate->compute(12), nts::False);
    cr_assert_eq(gate->compute(14), nts::False);
    cr_assert_eq(gate->compute(15), nts::False);
    cr_assert_eq(gate->compute(1), nts::False);
}
