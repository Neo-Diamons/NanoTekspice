/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Tests_Input
*/

#include <criterion/criterion.h>

#include "src/parser/Factory.hpp"
#include "src/parser/Exception.hpp"

static auto input = std::make_shared<nts::InputComponent>();
static std::size_t tick = 0;

Test(input, default_state)
{
    cr_assert_eq(input->compute(1), nts::Undefined);
}

Test(input, state)
{
    input->setState(nts::True);
    cr_assert_eq(input->compute(1), nts::Undefined);
}

Test(input, invalid_simulate)
{
    input->setState(nts::False);
    input->simulate(tick);
    input->setState(nts::True);
    input->simulate(tick);
    cr_assert_eq(input->compute(1), nts::False);
}

Test(input, invalid_pin)
{
    try {
        input->compute(2);
    } catch (nts::ExceptionInvalidPin &e) {
        cr_assert_str_eq(e.what(), "Input: Invalid pin");
    }
}
