/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Tests_4001
*/

#include <criterion/criterion.h>

#include "src/parsing/Factory.hpp"
#include "src/parsing/Exception.hpp"

static auto gate = std::make_shared<nts::Gates4001>();
static auto in_1 = std::make_shared<nts::ClockComponent>();
static auto in_2 = std::make_shared<nts::ClockComponent>();
static auto in_3 = std::make_shared<nts::ClockComponent>();
static auto in_4 = std::make_shared<nts::ClockComponent>();
static auto in_5 = std::make_shared<nts::ClockComponent>();
static auto in_6 = std::make_shared<nts::ClockComponent>();
static auto in_7 = std::make_shared<nts::ClockComponent>();
static auto in_8 = std::make_shared<nts::ClockComponent>();
static std::size_t tick = 0;

static void setup4001()
{
    nts::Link::setLink(gate, 1, in_1, 1);
    nts::Link::setLink(gate, 2, in_2, 1);
    nts::Link::setLink(gate, 5, in_3, 1);
    nts::Link::setLink(gate, 6, in_4, 1);
    nts::Link::setLink(gate, 8, in_5, 1);
    nts::Link::setLink(gate, 9, in_6, 1);
    nts::Link::setLink(gate, 12, in_7, 1);
    nts::Link::setLink(gate, 13, in_8, 1);
}

static void terminate4001()
{
    const nts::Tristate res = gate->compute(3);
    cr_assert_eq(gate->compute(4), res);
    cr_assert_eq(gate->compute(10), res);
    cr_assert_eq(gate->compute(11), res);
}

Test(gate4001, default_state, .init = setup4001, .fini = terminate4001)
{
    cr_assert_eq(gate->compute(3), nts::Undefined);
}

Test(gate4001, input_false, .init = setup4001, .fini = terminate4001)
{
    in_1->setState(nts::False);
    in_2->setState(nts::False);
    in_3->setState(nts::False);
    in_4->setState(nts::False);
    in_5->setState(nts::False);
    in_6->setState(nts::False);
    in_7->setState(nts::False);
    in_8->setState(nts::False);

    gate->simulate(tick++);

    cr_assert_eq(gate->compute(3), nts::True);
}

Test(gate4001, input_true, .init = setup4001, .fini = terminate4001)
{
    in_1->setState(nts::True);
    in_2->setState(nts::True);
    in_3->setState(nts::True);
    in_4->setState(nts::True);
    in_5->setState(nts::True);
    in_6->setState(nts::True);
    in_7->setState(nts::True);
    in_8->setState(nts::True);

    gate->simulate(tick++);

    cr_assert_eq(gate->compute(3), nts::False);
}

Test(gate4001, input_undefined, .init = setup4001, .fini = terminate4001)
{
    in_1->setState(nts::Undefined);
    in_2->setState(nts::Undefined);
    in_3->setState(nts::Undefined);
    in_4->setState(nts::Undefined);
    in_5->setState(nts::Undefined);
    in_6->setState(nts::Undefined);
    in_7->setState(nts::Undefined);
    in_8->setState(nts::Undefined);

    gate->simulate(tick++);

    cr_assert_eq(gate->compute(3), nts::Undefined);
}

Test(gate4001, input_true_false, .init = setup4001, .fini = terminate4001)
{
    in_1->setState(nts::True);
    in_2->setState(nts::False);
    in_3->setState(nts::True);
    in_4->setState(nts::False);
    in_5->setState(nts::True);
    in_6->setState(nts::False);
    in_7->setState(nts::True);
    in_8->setState(nts::False);

    gate->simulate(tick++);

    cr_assert_eq(gate->compute(3), nts::False);
}

Test(gate4001, input_false_true, .init = setup4001)
{
    in_1->setState(nts::False);
    in_2->setState(nts::True);
    in_3->setState(nts::False);
    in_4->setState(nts::True);
    in_5->setState(nts::False);
    in_6->setState(nts::True);
    in_7->setState(nts::False);
    in_8->setState(nts::True);

    gate->simulate(tick++);

    cr_assert_eq(gate->compute(3), nts::False);
}

Test(gate4001, invalid_simulate, .init = setup4001)
{
    in_1->setState(nts::False);
    in_2->setState(nts::False);
    in_3->setState(nts::False);
    in_4->setState(nts::False);
    in_5->setState(nts::False);
    in_6->setState(nts::False);
    in_7->setState(nts::False);
    in_8->setState(nts::False);

    gate->simulate(tick);
    gate->simulate(tick);

    cr_assert_eq(gate->compute(3), nts::True);
}

Test(gate4001, invalid_pin, .init = setup4001)
{
    try {
        gate->compute(15);
    } catch (nts::ExceptionInvalidPin &e) {
        cr_assert_str_eq(e.what(), "4001: Invalid pin");
    }
}
