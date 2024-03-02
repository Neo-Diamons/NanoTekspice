/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** tests_4040
*/

#include <criterion/criterion.h>

#include "src/parsing/Factory.hpp"
#include "src/parsing/Exception.hpp"

static auto gate = std::make_shared<nts::Gates4040>();
static auto cl_clock = std::make_shared<nts::ClockComponent>();
static auto in_reset = std::make_shared<nts::InputComponent>();
static std::size_t tick = 0;

static void setup4040()
{
    nts::Link::setLink(gate, 10, cl_clock, 1);
    nts::Link::setLink(gate, 11, in_reset, 1);
}

Test(gate4040, default_state, .init = setup4040)
{
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

Test(gate4040, increase_to_1, .init = setup4040)
{
    cl_clock->setState(nts::False);
    in_reset->setState(nts::False);

    // Each time the clock is set to true, the value stored in the 4040 is incremented

    for (u_int8_t i = 0; i < 2; i++)
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
}

Test(gate4040, increase_to_2, .init = setup4040)
{
    cl_clock->setState(nts::False);
    in_reset->setState(nts::False);

    for (u_int8_t i = 0; i < 4; i++)
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
}

Test(gate4040, increase_to_3, .init = setup4040)
{
    cl_clock->setState(nts::False);
    in_reset->setState(nts::False);

    for (u_int8_t i = 0; i < 6; i++)
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
}

Test(gate4040, increase_to_max, .init = setup4040)
{
    cl_clock->setState(nts::False);
    in_reset->setState(nts::False);

    for (u_int32_t i = 0; i < 4095 * 2; i++)
        gate->simulate(tick++);

    cr_assert_eq(gate->compute(9), nts::True);
    cr_assert_eq(gate->compute(7), nts::True);
    cr_assert_eq(gate->compute(6), nts::True);
    cr_assert_eq(gate->compute(5), nts::True);
    cr_assert_eq(gate->compute(3), nts::True);
    cr_assert_eq(gate->compute(2), nts::True);
    cr_assert_eq(gate->compute(4), nts::True);
    cr_assert_eq(gate->compute(13), nts::True);
    cr_assert_eq(gate->compute(12), nts::True);
    cr_assert_eq(gate->compute(14), nts::True);
    cr_assert_eq(gate->compute(15), nts::True);
    cr_assert_eq(gate->compute(1), nts::True);
}

Test(gate4040, increase_to_overflow, .init = setup4040)
{
    cl_clock->setState(nts::False);
    in_reset->setState(nts::False);

    for (u_int32_t i = 0; i < 4096 * 2; i++)
        gate->simulate(tick++);

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

Test(gate4040, increase_to_3_and_reset, .init = setup4040)
{
    cl_clock->setState(nts::False);
    in_reset->setState(nts::False);

    for (u_int8_t i = 0; i < 6; i++)
        gate->simulate(tick++);

    in_reset->setState(nts::True);
    gate->simulate(tick++);

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

Test(gate4040, invalid_simulate, .init = setup4040)
{
    cl_clock->setState(nts::False);
    in_reset->setState(nts::False);

    for (u_int8_t i = 0; i < 4; i++)
        gate->simulate(tick);

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

Test(gate4040, invalid_pin, .init = setup4040)
{
    try {
        gate->compute(16);
    } catch (nts::ExceptionInvalidPin &e) {
        cr_assert_str_eq(e.what(), "4040: Invalid pin");
    }
}
