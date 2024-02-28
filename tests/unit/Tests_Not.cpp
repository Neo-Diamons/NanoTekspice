/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Tests_Not
*/

#include <criterion/criterion.h>

#include "src/parser/Factory.hpp"
#include "src/parser/Exception.hpp"

static auto gate = std::make_shared<nts::NotComponent>();
static auto input = std::make_shared<nts::InputComponent>();

void setup_not()
{
    nts::Link::setLink(gate, 1, input, 1);
}

Test(Not, false, .init = setup_not)
{
    input->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(2), nts::True);
}

Test(Not, true, .init = setup_not)
{
    input->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(2), nts::False);
}

Test(Not, undef, .init = setup_not)
{
    input->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(2), nts::Undefined);
}

Test(Not, invalid_pin, .init = setup_not)
{
    try {
        gate->compute(3);
    } catch (nts::ExceptionInvalidPin &e) {
        cr_assert_str_eq(e.what(), "Not: Invalid pin");
    }
}

Test(Not, compute_first_pin_true, .init = setup_not)
{
    input->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(1), nts::True);
}

Test(Not, compute_first_pin_false, .init = setup_not)
{
    input->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(1), nts::False);
}

Test(Not, compute_first_pin_undef, .init = setup_not)
{
    input->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(1), nts::Undefined);
}
