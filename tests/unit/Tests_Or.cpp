/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Tests_Or
*/

#include <criterion/criterion.h>

#include "src/parsing/Factory.hpp"
#include "src/parsing/Exception.hpp"

static auto gate = std::make_shared<nts::OrComponent>();
static auto input1 = std::make_shared<nts::InputComponent>();
static auto input2 = std::make_shared<nts::InputComponent>();

static void setup_or()
{
    nts::Link::setLink(gate, 1, input1, 1);
    nts::Link::setLink(gate, 2, input2, 1);
}

Test(Or, false_false, .init = setup_or)
{
    input1->setState(nts::False);
    input2->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::False);
}

Test(Or, true_false, .init = setup_or)
{
    input1->setState(nts::True);
    input2->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::True);
}

Test(Or, false_true, .init = setup_or)
{
    input1->setState(nts::False);
    input2->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::True);
}

Test(Or, true_true, .init = setup_or)
{
    input1->setState(nts::True);
    input2->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::True);
}

Test(Or, undef_undef, .init = setup_or)
{
    input1->setState(nts::Undefined);
    input2->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::Undefined);
}

Test(Or, undef_true, .init = setup_or)
{
    input1->setState(nts::Undefined);
    input2->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::True);
}

Test(Or, true_undef, .init = setup_or)
{
    input1->setState(nts::True);
    input2->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::True);
}

Test(Or, false_undef, .init = setup_or)
{
    input1->setState(nts::False);
    input2->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::Undefined);
}

Test(Or, undef_false, .init = setup_or)
{
    input1->setState(nts::Undefined);
    input2->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::Undefined);
}

Test(Or, invalid_pin, .init = setup_or)
{
    try {
        gate->compute(4);
    } catch (nts::ExceptionInvalidPin &e) {
        cr_assert_str_eq(e.what(), "Or: Invalid pin");
    }
}

Test(Or, compute_firts_pin_true, .init = setup_or)
{
    input1->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(1), nts::True);
}

Test(Or, compute_firts_pin_false, .init = setup_or)
{
    input1->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(1), nts::False);
}

Test(Or, compute_firts_pin_undef, .init = setup_or)
{
    input1->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(1), nts::Undefined);
}

Test(Or, compute_second_pin_true, .init = setup_or)
{
    input2->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(2), nts::True);
}

Test(Or, compute_second_pin_false, .init = setup_or)
{
    input2->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(2), nts::False);
}

Test(Or, compute_second_pin_undef, .init = setup_or)
{
    input2->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(2), nts::Undefined);
}
