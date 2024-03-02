/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** tests_4013
*/

#include <criterion/criterion.h>

#include "src/parsing/Factory.hpp"
#include "src/parsing/Exception.hpp"

static auto gate = std::make_shared<nts::Gates4013>();
static auto in_1_data = std::make_shared<nts::InputComponent>();
static auto in_1_set = std::make_shared<nts::InputComponent>();
static auto in_1_reset = std::make_shared<nts::InputComponent>();
static auto cl_1_clock = std::make_shared<nts::ClockComponent>();
static auto in_2_data = std::make_shared<nts::InputComponent>();
static auto in_2_set = std::make_shared<nts::InputComponent>();
static auto in_2_reset = std::make_shared<nts::InputComponent>();
static auto cl_2_clock = std::make_shared<nts::ClockComponent>();
static std::size_t tick = 0;

static void setup4013()
{
    nts::Link::setLink(gate, 5, in_1_data, 1);
    nts::Link::setLink(gate, 6, in_1_set, 1);
    nts::Link::setLink(gate, 4, in_1_reset, 1);
    nts::Link::setLink(gate, 3, cl_1_clock, 1);

    nts::Link::setLink(gate, 9, in_2_data, 1);
    nts::Link::setLink(gate, 8, in_2_set, 1);
    nts::Link::setLink(gate, 10, in_2_reset, 1);
    nts::Link::setLink(gate, 11, cl_2_clock, 1);
}

static void terminate4013()
{
    cr_assert_eq(gate->compute(13), gate->compute(1));
    cr_assert_eq(gate->compute(12), gate->compute(2));
}

Test(gate4013, default_state, .init = setup4013, .fini = terminate4013)
{
    cr_assert_eq(gate->compute(1), nts::Undefined);
    cr_assert_eq(gate->compute(2), nts::Undefined);
}

Test(gate4013, clock_hight_data_false, .init = setup4013, .fini = terminate4013)
{
    in_1_data->setState(nts::False);
    in_1_set->setState(nts::False);
    in_1_reset->setState(nts::False);
    cl_1_clock->setState(nts::True);

    in_2_data->setState(nts::False);
    in_2_set->setState(nts::False);
    in_2_reset->setState(nts::False);
    cl_2_clock->setState(nts::True);

    gate->simulate(tick++);

    cr_assert_eq(gate->compute(1), nts::False);
    cr_assert_eq(gate->compute(2), nts::True);
}

Test(gate4013, clock_hight_data_true, .init = setup4013, .fini = terminate4013)
{
    in_1_data->setState(nts::True);
    in_1_set->setState(nts::False);
    in_1_reset->setState(nts::False);
    cl_1_clock->setState(nts::True);

    in_2_data->setState(nts::True);
    in_2_set->setState(nts::False);
    in_2_reset->setState(nts::False);
    cl_2_clock->setState(nts::True);

    gate->simulate(tick++);

    cr_assert_eq(gate->compute(1), nts::True);
    cr_assert_eq(gate->compute(2), nts::False);
}

Test(gate4013, clock_down, .init = setup4013, .fini = terminate4013)
{
    in_1_data->setState(nts::False);
    in_1_set->setState(nts::False);
    in_1_reset->setState(nts::False);
    cl_1_clock->setState(nts::False);

    in_2_data->setState(nts::False);
    in_2_set->setState(nts::False);
    in_2_reset->setState(nts::False);
    cl_2_clock->setState(nts::False);

    gate->simulate(tick++);

    cr_assert_eq(gate->compute(1), nts::Undefined);
    cr_assert_eq(gate->compute(2), nts::Undefined);
}

Test(gate4013, reset_true_set_false, .init = setup4013, .fini = terminate4013)
{
    in_1_set->setState(nts::False);
    in_1_reset->setState(nts::True);

    in_2_set->setState(nts::False);
    in_2_reset->setState(nts::True);

    gate->simulate(tick++);

    cr_assert_eq(gate->compute(1), nts::False);
    cr_assert_eq(gate->compute(2), nts::True);
}

Test(gate4013, reset_true_set_true, .init = setup4013, .fini = terminate4013)
{
    in_1_set->setState(nts::True);
    in_1_reset->setState(nts::True);

    in_2_set->setState(nts::True);
    in_2_reset->setState(nts::True);

    gate->simulate(tick++);

    cr_assert_eq(gate->compute(1), nts::True);
    cr_assert_eq(gate->compute(2), nts::True);
}

Test(gate4013, reset_false, .init = setup4013, .fini = terminate4013)
{
    in_1_set->setState(nts::False);
    in_1_reset->setState(nts::True);

    in_2_set->setState(nts::False);
    in_2_reset->setState(nts::True);

    gate->simulate(tick++);

    cr_assert_eq(gate->compute(1), nts::False);
    cr_assert_eq(gate->compute(2), nts::True);
}

Test(gate4013, invalid_simulate, .init = setup4013)
{
    in_1_set->setState(nts::False);
    in_1_reset->setState(nts::True);

    in_2_set->setState(nts::False);
    in_2_reset->setState(nts::True);

    gate->simulate(tick);
    gate->simulate(tick);

    cr_assert_eq(gate->compute(1), nts::False);
    cr_assert_eq(gate->compute(2), nts::True);
}

Test(gate4013, invalid_pin, .init = setup4013)
{
    try {
        gate->compute(16);
    } catch (nts::ExceptionInvalidPin &e) {
        cr_assert_str_eq(e.what(), "4013: Invalid pin");
    }
}
