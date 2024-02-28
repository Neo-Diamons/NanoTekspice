/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Tests_True
*/

#include <criterion/criterion.h>

#include "src/parser/Factory.hpp"
#include "src/parser/Exception.hpp"

static auto trueComp = std::make_shared<nts::TrueComponent>();

Test(true, default_state)
{
    cr_assert_eq(trueComp->compute(1), nts::True);
}

Test(true, invalid_pin)
{
    try {
        trueComp->compute(2);
    } catch (nts::ExceptionInvalidPin &e) {
        cr_assert_str_eq(e.what(), "True: Invalid pin");
    }
}
