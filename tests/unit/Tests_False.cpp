/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Tests_False
*/

#include <criterion/criterion.h>

#include "src/parser/Factory.hpp"
#include "src/parser/Exception.hpp"

static auto falseComp = std::make_shared<nts::FalseComponent>();

Test(false, default_state)
{
    cr_assert_eq(falseComp->compute(1), nts::False);
}

Test(false, invalid_pin)
{
    try {
        falseComp->compute(2);
    } catch (nts::ExceptionInvalidPin &e) {
        cr_assert_str_eq(e.what(), "False: Invalid pin");
    }
}
