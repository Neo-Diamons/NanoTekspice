/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Tests_4069
*/

#include <criterion/criterion.h>

#include "src/parsing/Factory.hpp"
#include "src/parsing/Exception.hpp"

static auto gate = std::make_shared<nts::Gates4069>();
static auto in_1 = std::make_shared<nts::ClockComponent>();
static auto in_2 = std::make_shared<nts::ClockComponent>();
static auto in_3 = std::make_shared<nts::ClockComponent>();
static auto in_4 = std::make_shared<nts::ClockComponent>();
static auto in_5 = std::make_shared<nts::ClockComponent>();
static auto in_6 = std::make_shared<nts::ClockComponent>();
static std::size_t tick = 0;

static void setup4069()
{
    nts::Link::setLink(gate, 1, in_1, 1);
    nts::Link::setLink(gate, 3, in_2, 1);
    nts::Link::setLink(gate, 5, in_3, 1);
    nts::Link::setLink(gate, 9, in_4, 1);
    nts::Link::setLink(gate, 11, in_5, 1);
    nts::Link::setLink(gate, 13, in_6, 1);
}

static void terminate4069()
{
    const nts::Tristate res = gate->compute(2);
    cr_assert_eq(gate->compute(4), res);
    cr_assert_eq(gate->compute(6), res);
    cr_assert_eq(gate->compute(8), res);
    cr_assert_eq(gate->compute(10), res);
    cr_assert_eq(gate->compute(12), res);
}

Test(gate4069, default_state, .init = setup4069, .fini = terminate4069)
{
    cr_assert_eq(gate->compute(3), nts::Undefined);
}

Test(gate4069, input_false, .init = setup4069, .fini = terminate4069)
{
    in_1->setState(nts::False);
    in_2->setState(nts::False);
    in_3->setState(nts::False);
    in_4->setState(nts::False);
    in_5->setState(nts::False);
    in_6->setState(nts::False);

    gate->simulate(tick++);

    cr_assert_eq(gate->compute(2), nts::True);
}

Test(gate4069, input_true, .init = setup4069, .fini = terminate4069)
{
    in_1->setState(nts::True);
    in_2->setState(nts::True);
    in_3->setState(nts::True);
    in_4->setState(nts::True);
    in_5->setState(nts::True);
    in_6->setState(nts::True);

    gate->simulate(tick++);

    cr_assert_eq(gate->compute(2), nts::False);
}

Test(gate4069, input_undefined, .init = setup4069, .fini = terminate4069)
{
    in_1->setState(nts::Undefined);
    in_2->setState(nts::Undefined);
    in_3->setState(nts::Undefined);
    in_4->setState(nts::Undefined);
    in_5->setState(nts::Undefined);
    in_6->setState(nts::Undefined);

    gate->simulate(tick++);

    cr_assert_eq(gate->compute(2), nts::Undefined);
}

Test(gate4069, invalid_simulate, .init = setup4069)
{
    in_1->setState(nts::False);
    in_2->setState(nts::False);
    in_3->setState(nts::False);
    in_4->setState(nts::False);
    in_5->setState(nts::False);
    in_6->setState(nts::False);

    gate->simulate(tick);
    gate->simulate(tick);

    cr_assert_eq(gate->compute(2), nts::True);
}

Test(gate4069, invalid_pin, .init = setup4069)
{
    try {
        gate->compute(15);
    } catch (nts::ExceptionInvalidPin &e) {
        cr_assert_str_eq(e.what(), "4069: Invalid pin");
    }
}
