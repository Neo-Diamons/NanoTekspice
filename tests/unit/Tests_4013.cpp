/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** tests_4013
*/

#include <criterion/criterion.h>
#include <iostream>

#include "src/parser/Factory.hpp"

Test(test4013, test00)
{
    auto gate = std::make_shared<nts::Gates4013>();

    auto in_1_data = std::make_shared<nts::FalseComponent>();
    auto in_1_set = std::make_shared<nts::FalseComponent>();
    auto in_1_reset = std::make_shared<nts::FalseComponent>();
    auto cl_1_clock = std::make_shared<nts::ClockComponent>();

    auto in_2_data = std::make_shared<nts::TrueComponent>();
    auto in_2_set = std::make_shared<nts::FalseComponent>();
    auto in_2_reset = std::make_shared<nts::FalseComponent>();
    auto cl_2_clock = std::make_shared<nts::ClockComponent>();

    nts::Link::setLink(gate, 5, in_1_data, 1);
    nts::Link::setLink(gate, 6, in_1_set, 1);
    nts::Link::setLink(gate, 4, in_1_reset, 1);
    nts::Link::setLink(gate, 3, cl_1_clock, 1);

    nts::Link::setLink(gate, 9, in_2_data, 1);
    nts::Link::setLink(gate, 8, in_2_set, 1);
    nts::Link::setLink(gate, 10, in_2_reset, 1);
    nts::Link::setLink(gate, 11, cl_2_clock, 1);

    gate->simulate(2);

    cr_assert_eq(gate->compute(1), nts::False);
    cr_assert_eq(gate->compute(2), nts::True);

    cr_assert_eq(gate->compute(13), nts::True);
    cr_assert_eq(gate->compute(12), nts::False);
}

Test(test4013, test01)
{
    auto gate = std::make_shared<nts::Gates4013>();

    auto in_1_data = std::make_shared<nts::FalseComponent>();
    auto in_1_set = std::make_shared<nts::FalseComponent>();
    auto in_1_reset = std::make_shared<nts::FalseComponent>();
    auto cl_1_clock = std::make_shared<nts::ClockComponent>();

    auto in_2_data = std::make_shared<nts::FalseComponent>();
    auto in_2_set = std::make_shared<nts::FalseComponent>();
    auto in_2_reset = std::make_shared<nts::TrueComponent>();
    auto cl_2_clock = std::make_shared<nts::ClockComponent>();

    nts::Link::setLink(gate, 5, in_1_data, 1);
    nts::Link::setLink(gate, 6, in_1_set, 1);
    nts::Link::setLink(gate, 4, in_1_reset, 1);
    nts::Link::setLink(gate, 3, cl_1_clock, 1);

    nts::Link::setLink(gate, 9, in_2_data, 1);
    nts::Link::setLink(gate, 8, in_2_set, 1);
    nts::Link::setLink(gate, 10, in_2_reset, 1);
    nts::Link::setLink(gate, 11, cl_2_clock, 1);

    gate->simulate(1);

    cr_assert_eq(gate->compute(1), nts::Undefined);
    cr_assert_eq(gate->compute(2), nts::Undefined);

    cr_assert_eq(gate->compute(13), nts::False);
    cr_assert_eq(gate->compute(12), nts::True);
}
