/*
** EPITECH PROJECT, 2024
** NanoTekspice
** File description:
** Tests_Link
*/

#include <criterion/criterion.h>

#include "src/parsing/Factory.hpp"
#include "src/parsing/Exception.hpp"

static auto gate = std::make_shared<nts::NotComponent>();
static auto in = std::make_shared<nts::InputComponent>();
static auto out = std::make_shared<nts::OutputComponent>();

Test(link, set_valid_link_in_to_out)
{
    cr_assert_no_throw(nts::Link::setLink(gate, 1, in, 1), nts::ExceptionInvalidPin);
    cr_assert_no_throw(nts::Link::setLink(gate, 2, out, 1), nts::ExceptionInvalidPin);
}

Test(link, set_valid_link_out_to_in)
{
    cr_assert_no_throw(nts::Link::setLink(in, 1, gate, 1), nts::ExceptionInvalidPin);
    cr_assert_no_throw(nts::Link::setLink(out, 1, gate, 2), nts::ExceptionInvalidPin);
}

Test(link, set_invalid_link_out_to_out)
{
    cr_assert_throw(nts::Link::setLink(out, 1, out, 1), nts::ExceptionInvalidPin);
}
