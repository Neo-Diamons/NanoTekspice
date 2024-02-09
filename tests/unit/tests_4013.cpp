/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** tests_4013
*/

#include <criterion/criterion.h>
#include <iostream>
#include "src/IComponent.hpp"

Test(test4013, test00)
{
    nts::Gates4013 gate;

    auto in_1_data = std::make_shared<nts::FalseComponent>();
    auto in_1_set = std::make_shared<nts::FalseComponent>();
    auto in_1_reset = std::make_shared<nts::FalseComponent>();
    auto cl_1_clock = std::make_shared<nts::ClockComponent>();

    auto in_2_data = std::make_shared<nts::TrueComponent>();
    auto in_2_set = std::make_shared<nts::FalseComponent>();
    auto in_2_reset = std::make_shared<nts::FalseComponent>();
    auto cl_2_clock = std::make_shared<nts::ClockComponent>();

    gate.setLink(5, in_1_data, 1);
    gate.setLink(6, in_1_set, 1);
    gate.setLink(4, in_1_reset, 1);
    gate.setLink(3, cl_1_clock, 1);

    gate.setLink(9, in_2_data, 1);
    gate.setLink(8, in_2_set, 1);
    gate.setLink(10, in_2_reset, 1);
    gate.setLink(11, cl_2_clock, 1);

    gate.simulate(2);

    cr_assert_eq(gate.compute(1), nts::False);
    cr_assert_eq(gate.compute(2), nts::True);

    cr_assert_eq(gate.compute(13), nts::True);
    cr_assert_eq(gate.compute(12), nts::False);
}

Test(test4013, test01)
{
    nts::Gates4013 gate;

    auto in_1_data = std::make_shared<nts::FalseComponent>();
    auto in_1_set = std::make_shared<nts::FalseComponent>();
    auto in_1_reset = std::make_shared<nts::FalseComponent>();
    auto cl_1_clock = std::make_shared<nts::ClockComponent>();

    auto in_2_data = std::make_shared<nts::FalseComponent>();
    auto in_2_set = std::make_shared<nts::FalseComponent>();
    auto in_2_reset = std::make_shared<nts::TrueComponent>();
    auto cl_2_clock = std::make_shared<nts::ClockComponent>();

    gate.setLink(5, in_1_data, 1);
    gate.setLink(6, in_1_set, 1);
    gate.setLink(4, in_1_reset, 1);
    gate.setLink(3, cl_1_clock, 1);

    gate.setLink(9, in_2_data, 1);
    gate.setLink(8, in_2_set, 1);
    gate.setLink(10, in_2_reset, 1);
    gate.setLink(11, cl_2_clock, 1);

    gate.simulate(1);

    cr_assert_eq(gate.compute(1), nts::Undefined);
    cr_assert_eq(gate.compute(2), nts::Undefined);

    cr_assert_eq(gate.compute(13), nts::False);
    cr_assert_eq(gate.compute(12), nts::True);
}
