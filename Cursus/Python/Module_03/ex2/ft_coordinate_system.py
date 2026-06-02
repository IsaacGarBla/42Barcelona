#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_coordinate_system.py                           :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/01 12:41:16 by igarciab        #+#    #+#               #
#  Updated: 2026/06/02 11:01:32 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import math


class FormatError(Exception):
    def __init__(selt, desc_error: str) -> None:
        super().__init__(desc_error)


def ft_is_space(char: str) -> bool:
    return char in " \t\v\f\r\n"


def ft_is_digit(char: str) -> bool:
    return char in "0123456789"


def ft_is_float(text: str) -> bool:
    has_point: bool = False
    has_valid_chars = False
    pos: int = 0

    if text == "":
        return False

    for c in text:
        # Check if there is a sign in a position other tha0.
        if c in "+-":
            if pos != 0:
                return False
        # Check the point.
        if c == ".":
            # Check if there is a point yet.
            if has_point:
                return False
            has_point = True
        # Check if is a valid digit
        elif ft_is_digit(c):
            has_valid_chars = True
        else:
            return False
        pos += 1

    # If it has valid digits with or without a point is a valid float.
    return has_valid_chars


def ft_to_float(str_number: str) -> float:
    int_part: float = 0
    dec_part: float = 0
    in_decimal_part: bool = False
    num_decimales: int = 0
    signo: int = 1
    digits = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4,
              '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

    if not ft_is_float(ft_trim(str_number)):
        raise FormatError(f"Could not convert strint to a float: "
                          f"'{ft_trim(str_number)}'")
    for c in ft_trim(str_number):
        if c in "+-":
            if c == "-":
                signo = - 1
        elif c == ".":
            in_decimal_part = True
        elif not in_decimal_part:
            int_part = int_part * 10 + digits[c]
        else:
            dec_part = dec_part * 10 + digits[c]
            num_decimales += 1
    if num_decimales != 0:
        dec_part = dec_part / (10 ** num_decimales)
    return (int_part + dec_part) * signo


# Erases white spaces at the begining and end of the string.
def ft_trim(str1: str) -> str:
    str_dst: str = ""
    str_spc: str = ""

    for c in str1:
        if ft_is_space(c):
            if str_dst != "":
                str_spc += c
        elif str_spc != "":
            str_dst += str_spc
            str_dst += c
            str_spc = ""
        else:
            str_dst += c
    return str_dst


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


def ft_len(list_items: list[str]) -> int:
    count: int = 0

    for item in list_items:
        count += 1
    return count


def get_player_pos() -> tuple[float, float, float]:
    args: list[str] = []
    coordinates: list[float] = []
    pos_got: bool = False

    while not pos_got:
        args = ft_split_input(input("Enter new coordinates as "
                                    "floats in format 'x,y,z': "), ",")
        if ft_len(args) != 3:
            print("Invalid syntax")
        else:
            try:
                for number in args:
                    coordinates.append(ft_to_float(number))
                pos_got = True
            except FormatError as error:
                print(f"Error on parameter '{ft_trim(number)}': {error}")
    return coordinates[0], coordinates[1], coordinates[2]


def main() -> None:
    first_coord: tuple[float, float, float]
    second_coord: tuple[float, float, float]
    distance: float

    print("Get a second set of coordinates")
    first_coord = get_player_pos()
    print(f"Got a first tuple: ({round(first_coord[0], 2):.2f}"
          f", {round(first_coord[1], 2):.2f}"
          f", {round(first_coord[2], 2):.2f})")
    print(f"It includes: X={round(first_coord[0], 2):.2f}, "
          f"Y={round(first_coord[1], 2):.2f}, "
          f"Z={round(first_coord[2], 2):.2f}")
    distance = math.sqrt((first_coord[0] - 0) ** 2 +
                         (first_coord[1] - 0) ** 2 +
                         (first_coord[2] - 0) ** 2)
    print(f"Distance to de center: {distance:.4f}")
    print("\nGet a second set of coordinates")
    second_coord = get_player_pos()
    distance = math.sqrt((first_coord[0] - second_coord[0]) ** 2 +
                         (first_coord[1] - second_coord[1]) ** 2 +
                         (first_coord[2] - second_coord[2]) ** 2)
    print(f"Distance between the 2 set of coordinates: {distance:.4f}")


if __name__ == "__main__":
    main()
