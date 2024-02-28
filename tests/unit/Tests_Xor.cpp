/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Tests_Xor
*/

#include <criterion/criterion.h>

#include "src/parser/Factory.hpp"
#include "src/parser/Exception.hpp"

static auto gate = std::make_shared<nts::XorComponent>();
static auto input1 = std::make_shared<nts::InputComponent>();
static auto input2 = std::make_shared<nts::InputComponent>();

static void setup_xor()
{
    nts::Link::setLink(gate, 1, input1, 1);
    nts::Link::setLink(gate, 2, input2, 1);
}

Test(Xor, false_false, .init = setup_xor)
{
    input1->setState(nts::False);
    input2->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::False);
}

Test(Xor, true_false, .init = setup_xor)
{
    input1->setState(nts::True);
    input2->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::True);
}

Test(Xor, false_true, .init = setup_xor)
{
    input1->setState(nts::False);
    input2->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::True);
}

Test(Xor, true_true, .init = setup_xor)
{
    input1->setState(nts::True);
    input2->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::False);
}

Test(Xor, undef_undef, .init = setup_xor)
{
    input1->setState(nts::Undefined);
    input2->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::Undefined);
}

Test(Xor, undef_true, .init = setup_xor)
{
    input1->setState(nts::Undefined);
    input2->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::Undefined);
}

Test(Xor, true_undef, .init = setup_xor)
{
    input1->setState(nts::True);
    input2->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::Undefined);
}

Test(Xor, false_undef, .init = setup_xor)
{
    input1->setState(nts::False);
    input2->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::Undefined);
}

Test(Xor, undef_false, .init = setup_xor)
{
    input1->setState(nts::Undefined);
    input2->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(3), nts::Undefined);
}

Test(Xor, invalid_pin, .init = setup_xor)
{
    try {
        gate->compute(4);
    } catch (nts::ExceptionInvalidPin &e) {
        cr_assert_str_eq(e.what(), "Xor: Invalid pin");
    }
}

Test(Xor, compute_first_pin_true, .init = setup_xor)
{
    input1->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(1), nts::True);
}

Test(Xor, compute_first_pin_false, .init = setup_xor)
{
    input1->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(1), nts::False);
}

Test(Xor, compute_first_pin_undef, .init = setup_xor)
{
    input1->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(1), nts::Undefined);
}

Test(Xor, compute_second_pin_true, .init = setup_xor)
{
    input2->setState(nts::True);

    gate->simulate(1);
    cr_assert_eq(gate->compute(2), nts::True);
}

Test(Xor, compute_second_pin_false, .init = setup_xor)
{
    input2->setState(nts::False);

    gate->simulate(1);
    cr_assert_eq(gate->compute(2), nts::False);
}

Test(Xor, compute_second_pin_undef, .init = setup_xor)
{
    input2->setState(nts::Undefined);

    gate->simulate(1);
    cr_assert_eq(gate->compute(2), nts::Undefined);
}
