/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Tests_And
*/

#include <criterion/criterion.h>

#include "src/parser/Factory.hpp"
#include "src/parser/Exception.hpp"

static auto gate = std::make_shared<nts::AndComponent>();
static auto input1 = std::make_shared<nts::InputComponent>();
static auto input2 = std::make_shared<nts::InputComponent>();

void setup_and()
{
    nts::Link::setLink(gate, 1, input1, 1);
    nts::Link::setLink(gate, 2, input2, 1);
}

Test(And, false_false, .init = setup_and)
{
    input1->setState(nts::False);
    input2->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::False);
}

Test(And, true_false, .init = setup_and)
{
    input1->setState(nts::True);
    input2->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::False);
}

Test(And, false_true, .init = setup_and)
{
    input1->setState(nts::False);
    input2->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::False);
}

Test(And, true_true, .init = setup_and)
{
    input1->setState(nts::True);
    input2->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::True);
}

Test(And, undef_undef, .init = setup_and)
{
    input1->setState(nts::Undefined);
    input2->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::Undefined);
}

Test(And, undef_true, .init = setup_and)
{
    input1->setState(nts::Undefined);
    input2->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::Undefined);
}

Test(And, true_undef, .init = setup_and)
{
    input1->setState(nts::True);
    input2->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::Undefined);
}

Test(And, false_undef, .init = setup_and)
{
    input1->setState(nts::False);
    input2->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::False);
}

Test(And, undef_false, .init = setup_and)
{
    input1->setState(nts::Undefined);
    input2->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::False);
}

Test(And, invalid_pin, .init = setup_and)
{
    try {
        gate->compute(4);
    } catch (nts::ExceptionInvalidPin &e) {
        cr_assert_str_eq(e.what(), "And: Invalid pin");
    }
}

Test(And, compute_first_pin_true, .init = setup_and)
{
    input1->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(1), nts::True);
}

Test(And, compute_first_pin_false, .init = setup_and)
{
    input1->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(1), nts::False);
}

Test(And, compute_first_pin_undef, .init = setup_and)
{
    input1->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(1), nts::Undefined);
}

Test(And, compute_second_pin_true, .init = setup_and)
{
    input2->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(2), nts::True);
}

Test(And, compute_second_pin_false, .init = setup_and)
{
    input2->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(2), nts::False);
}

Test(And, compute_second_pin_undef, .init = setup_and)
{
    input2->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(2), nts::Undefined);
}
