/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** tests_4008
*/

#include <criterion/criterion.h>
#include "src/IComponent.hpp"

Test(gates4008, test00)
{
    nts::Gates4008 gate;

    auto in_a1 = std::make_shared<nts::InputComponent>();
    auto in_a2 = std::make_shared<nts::InputComponent>();
    auto in_a3 = std::make_shared<nts::InputComponent>();
    auto in_a4 = std::make_shared<nts::InputComponent>();
    auto in_b1 = std::make_shared<nts::InputComponent>();
    auto in_b2 = std::make_shared<nts::InputComponent>();
    auto in_b3 = std::make_shared<nts::InputComponent>();
    auto in_b4 = std::make_shared<nts::InputComponent>();
    auto in_c = std::make_shared<nts::InputComponent>();

    in_c->setState(nts::True);

    in_a1->setState(nts::False);
    in_b1->setState(nts::False);

    in_a2->setState(nts::True);
    in_b2->setState(nts::False);

    in_a3->setState(nts::False);
    in_b3->setState(nts::True);

    in_a4->setState(nts::True);
    in_b4->setState(nts::True);

    gate.setLink(9, in_c, 1);

    gate.setLink(7, in_a1, 1);
    gate.setLink(6, in_b1, 1);

    gate.setLink(5, in_a2, 1);
    gate.setLink(4, in_b2, 1);

    gate.setLink(3, in_a3, 1);
    gate.setLink(2, in_b3, 1);

    gate.setLink(1, in_a4, 1);
    gate.setLink(15, in_b4, 1);

    gate.simulate(1);

    cr_assert_eq(gate.compute(10), nts::False);
    cr_assert_eq(gate.compute(11), nts::True);
    cr_assert_eq(gate.compute(12), nts::True);
    cr_assert_eq(gate.compute(13), nts::True);
    cr_assert_eq(gate.compute(14), nts::False);
}

Test(gates4008, test01)
{
    nts::Gates4008 gate;

    auto in_a1 = std::make_shared<nts::InputComponent>();
    auto in_a2 = std::make_shared<nts::InputComponent>();
    auto in_a3 = std::make_shared<nts::InputComponent>();
    auto in_a4 = std::make_shared<nts::InputComponent>();
    auto in_b1 = std::make_shared<nts::InputComponent>();
    auto in_b2 = std::make_shared<nts::InputComponent>();
    auto in_b3 = std::make_shared<nts::InputComponent>();
    auto in_b4 = std::make_shared<nts::InputComponent>();
    auto in_c = std::make_shared<nts::InputComponent>();

    in_c->setState(nts::True);

    in_a1->setState(nts::False);
    in_b1->setState(nts::True);

    in_a2->setState(nts::False);
    in_b2->setState(nts::True);

    in_a3->setState(nts::True);
    in_b3->setState(nts::True);

    in_a4->setState(nts::True);
    in_b4->setState(nts::False);

    gate.setLink(9, in_c, 1);

    gate.setLink(7, in_a1, 1);
    gate.setLink(6, in_b1, 1);

    gate.setLink(5, in_a2, 1);
    gate.setLink(4, in_b2, 1);

    gate.setLink(3, in_a3, 1);
    gate.setLink(2, in_b3, 1);

    gate.setLink(1, in_a4, 1);
    gate.setLink(15, in_b4, 1);

    gate.simulate(1);

    cr_assert_eq(gate.compute(10), nts::True);
    cr_assert_eq(gate.compute(11), nts::False);
    cr_assert_eq(gate.compute(12), nts::True);
    cr_assert_eq(gate.compute(13), nts::False);
    cr_assert_eq(gate.compute(14), nts::True);
}
