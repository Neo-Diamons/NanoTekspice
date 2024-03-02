/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** tests_4008
*/

#include <criterion/criterion.h>

#include "src/parsing/Factory.hpp"

static auto gate = std::make_shared<nts::Gates4008>();
static auto in_a1 = std::make_shared<nts::InputComponent>();
static auto in_a2 = std::make_shared<nts::InputComponent>();
static auto in_a3 = std::make_shared<nts::InputComponent>();
static auto in_a4 = std::make_shared<nts::InputComponent>();
static auto in_b1 = std::make_shared<nts::InputComponent>();
static auto in_b2 = std::make_shared<nts::InputComponent>();
static auto in_b3 = std::make_shared<nts::InputComponent>();
static auto in_b4 = std::make_shared<nts::InputComponent>();
static auto in_c = std::make_shared<nts::InputComponent>();
static std::size_t tick = 0;

void setup4008()
{
    nts::Link::setLink(gate, 9, in_c, 1);
    nts::Link::setLink(gate, 7, in_a1, 1);
    nts::Link::setLink(gate, 6, in_b1, 1);
    nts::Link::setLink(gate, 5, in_a2, 1);
    nts::Link::setLink(gate, 4, in_b2, 1);
    nts::Link::setLink(gate, 3, in_a3, 1);
    nts::Link::setLink(gate, 2, in_b3, 1);
    nts::Link::setLink(gate, 1, in_a4, 1);
    nts::Link::setLink(gate, 15, in_b4, 1);
}

Test(gate4008, add_1_to_1, .init = setup4008)
{
    in_c->setState(nts::False);

    // 1 (0b0001)
    in_a1->setState(nts::True);
    in_a2->setState(nts::False);
    in_a3->setState(nts::False);
    in_a4->setState(nts::False);

    // 1 (0b0001)
    in_b1->setState(nts::True);
    in_b2->setState(nts::False);
    in_b3->setState(nts::False);
    in_b4->setState(nts::False);

    gate->simulate(tick++);

    // 2 (0b0010)
    cr_assert_eq(gate->compute(10), nts::False);
    cr_assert_eq(gate->compute(11), nts::True);
    cr_assert_eq(gate->compute(12), nts::False);
    cr_assert_eq(gate->compute(13), nts::False);
}

Test(gate4008, add_1_to_1_with_carry, .init = setup4008)
{
    in_c->setState(nts::False);

    // 1 (0b0001)
    in_a1->setState(nts::True);
    in_a2->setState(nts::False);
    in_a3->setState(nts::False);
    in_a4->setState(nts::False);

    // 2 (0b0010)
    in_b1->setState(nts::False);
    in_b2->setState(nts::True);
    in_b3->setState(nts::False);
    in_b4->setState(nts::False);

    gate->simulate(tick++);

    // 3 (0b0011)
    cr_assert_eq(gate->compute(10), nts::True);
    cr_assert_eq(gate->compute(11), nts::True);
    cr_assert_eq(gate->compute(12), nts::False);
    cr_assert_eq(gate->compute(13), nts::False);
}
