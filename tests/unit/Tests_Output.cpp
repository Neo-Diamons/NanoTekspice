/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Tests_Output
*/

#include <criterion/criterion.h>

#include "src/parser/Factory.hpp"
#include "src/parser/Exception.hpp"

static auto output = std::make_shared<nts::OutputComponent>();
static auto clockComp = std::make_shared<nts::ClockComponent>();
static std::size_t tick = 0;

static void setupOutput()
{
    clockComp->setState(nts::False);
    nts::Link::setLink(output, 1, clockComp, 1);
}

Test(output, default_state)
{
    cr_assert_eq(output->compute(1), nts::Undefined);
}

Test(output, link, .init = setupOutput)
{
    output->simulate(tick++);
    cr_assert_eq(output->compute(1), nts::False);
}

Test(output, invalid_simulate, .init = setupOutput)
{
    for (u_int8_t i = 0; i < 2; i++)
        output->simulate(tick);
    cr_assert_eq(output->compute(1), nts::False);
}

Test(output, invalid_pin)
{
    try {
        output->compute(2);
    } catch (nts::ExceptionInvalidPin &e) {
        cr_assert_str_eq(e.what(), "Output: Invalid pin");
    }
}
