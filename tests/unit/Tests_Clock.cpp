/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Tests_Clock
*/

#include <criterion/criterion.h>

#include "src/parser/Factory.hpp"
#include "src/parser/Exception.hpp"

static auto clockComp = std::make_shared<nts::ClockComponent>();
static std::size_t tick = 0;

Test(clock, undef)
{
    cr_assert_eq(clockComp->compute(1), nts::Undefined);
}

Test(clock, set_undef)
{
    clockComp->setState(nts::True);

    cr_assert_eq(clockComp->compute(1), nts::Undefined);
}

Test(clock, set_true_simulate)
{
    clockComp->setState(nts::True);

    clockComp->simulate(tick++);
    cr_assert_eq(clockComp->compute(1), nts::True);
}

Test(clock, set_false_simulate)
{
    clockComp->setState(nts::False);

    clockComp->simulate(tick++);
    cr_assert_eq(clockComp->compute(1), nts::False);
}

Test(clock, set_true_false_simulate)
{
    clockComp->setState(nts::Undefined);

    clockComp->simulate(tick++);
    cr_assert_eq(clockComp->compute(1), nts::Undefined);
}

Test(clock, set_true_false_simulate_two)
{
    clockComp->setState(nts::True);

    clockComp->simulate(tick++);
    clockComp->simulate(tick++);
    cr_assert_eq(clockComp->compute(1), nts::False);
}

Test(clock, set_true_false_simulate_three)
{
    clockComp->setState(nts::False);

    clockComp->simulate(tick++);
    clockComp->simulate(tick++);
    cr_assert_eq(clockComp->compute(1), nts::True);
}

Test(clock, invalid_simulate)
{
    clockComp->setState(nts::False);
    for (u_int8_t i = 0; i < 2; i++)
        clockComp->simulate(tick);
    cr_assert_eq(clockComp->compute(1), nts::False);
}

Test(clock, invalid_pin)
{
    try {
        clockComp->compute(2);
    } catch (nts::ExceptionInvalidPin &e) {
        cr_assert_str_eq(e.what(), "Clock: Invalid pin");
    }
}
