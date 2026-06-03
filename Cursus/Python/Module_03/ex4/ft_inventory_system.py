#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_inventory_system.py                            :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/02 09:38:42 by igarciab        #+#    #+#               #
#  Updated: 2026/06/03 12:56:18 by igarcia-        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import sys


class FormatError(Exception):
    def __init__(selt, desc_error: str) -> None:
        super().__init__(desc_error)


# @ft_split_input: splits a string into a list of substrings based on a
# separator.
# @param input: The input string to be split.
# @param sep: The separator character.
# @return: A list of substrings.
def ft_split_input(input: str, sep: str) -> list[str]:
    word: str = ""
    word_list: list[str] = []

    for c in input:
        if c == sep:
            word_list.append(word)
            word = ""
        else:
            word += c
    if word != "":
        word_list.append(word)
    return word_list


# @ft_trim: removes leading and trailing whitespace from a string.
# @param str1: The input string to be trimmed.
# @return: A new string with leading and trailing whitespace removed.
def ft_trim(str1: str) -> str:
    str_dst: str = ""
    str_spc: str = ""

    for c in str1:
        if c in " \t\v\f\r\n":
            if str_dst != "":
                str_spc += c
        elif str_spc != "":
            str_dst += str_spc
            str_dst += c
            str_spc = ""
        else:
            str_dst += c
    return str_dst


# @ft_is_integer: checks if a string represents a valid integer.
# @param text: The input string to be checked.
# @return: True if the string is a valid integer, False otherwise.
def ft_is_integer(text: str) -> bool:
    has_valid_chars = False
    pos: int = 0

    if text == "":
        return False

    for c in text:
        if c in "+-":
            if pos != 0:
                return False
        elif c in "0123456789":
            has_valid_chars = True
        else:
            return False
        pos += 1
    return has_valid_chars


# @ft_to_integer: converts a string to an integer, handling optional
# leading '+' or '-' signs.
# @param str_number: The input string to be converted.
# @return: The integer value represented by the input string.
def ft_to_integer(str_number: str) -> int:
    res: int = 0
    signo: int = 1
    digits = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4,
              '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

    if not ft_is_integer(ft_trim(str_number)):
        raise FormatError(f"Could not convert string to an integer: "
                          f"'{ft_trim(str_number)}'")
    for c in ft_trim(str_number):
        if c in "+-":
            if c == "-":
                signo = - 1
        else:
            res = res * 10 + digits[c]
    return res * signo


# @ft_parse_input: parses the command-line arguments and creates an
# inventory dictionary.
# @return: A dictionary where keys are item names and values are quantities
# of those items.
def parse_input() -> dict[str, int]:
    inventory: dict[str, int] = {}
    entry: list[str]
    value: int
    key: str

    for i in range(1, len(sys.argv)):
        entry = ft_split_input(sys.argv[i], ":")
        if len(entry) != 2:
            print(f"Error - invalid parameter '{sys.argv[i]}'")
            continue
        try:
            value = ft_to_integer(ft_trim(entry[1]))
            key = ft_trim(entry[0])
            if key in inventory:
                print(f"Redundant item '{key}' - discarding")
            elif value < 0:
                print(f"Warning: Negative quantity for item '{key}'"
                      f": {value} - discarding")
            else:
                inventory[key] = value
        except FormatError:
            print(f"Quantity error for '{entry[0]}':"
                  f" Invalid literal for int() with base 10: '{entry[1]}'")
    return inventory


# @ft_print_inventory: prints the inventory details, including the total
# quantity of items, the percentage representation of each item, and the
# most and least abundant items.
# @param inventory: A dictionary where keys are item names and values are
# quantities of those items.
def print_inventory(inventory: dict[str, int]) -> None:
    max_item_name: str = ""
    max_item_quantity: int = -99999999999999999999999
    min_item_name: str = ""
    min_item_quantity: int = 99999999999999999999999

    print("Item list:", list(dict.keys(inventory)))
    print("Total quantity of the", len(inventory), "items:",
          sum(dict.values(inventory)))
    if len(inventory) == 0:
        return
    for each_item in inventory:
        print(f"Item {each_item} represents "
              f"{round(inventory[each_item]/sum(dict.values(inventory)) * 100,
                       1)}%")
        if inventory[each_item] > max_item_quantity:
            max_item_name = each_item
            max_item_quantity = inventory[each_item]
        if inventory[each_item] < min_item_quantity:
            min_item_name = each_item
            min_item_quantity = inventory[each_item]
    print(f"Item most abundant: '{max_item_name}' "
          f"with quantity {max_item_quantity}")
    print(f"Item least abundant: '{min_item_name}' "
          f"with quantity {min_item_quantity}")


def main() -> None:
    print("=== Inventory System Analysis ===")
    inventory = parse_input()
    print("Got inventory:", inventory)
    print_inventory(inventory)
    inventory["magic_item"] = 1
    print("Updated inventory:", inventory)


if __name__ == "__main__":
    main()
