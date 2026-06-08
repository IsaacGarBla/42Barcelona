#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_score_analytics.py                             :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/01 10:28:28 by igarciab        #+#    #+#               #
#  Updated: 2026/06/03 12:50:52 by igarcia-        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import sys


class NoNumber(Exception):
    def __init__(selt, desc_error: str) -> None:
        super().__init__(desc_error)


def ft_string_to_int(str_num: str) -> int:
    digits = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4,
              '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

    numero: int = 0
    for char in str_num:
        try:
            numero = numero * 10 + digits[char]
        except KeyError:
            raise NoNumber(f"El carácter {char} no es un dígito")
    return numero


# Processes arguments and returns two list:
# First list: scores introduced.
# Second list: error arguments.
def ft_process_arguments() -> tuple[list[int], list[str]]:
    score_list: list[int] = []
    error_list: list[str] = []

    # Process de arguments, except de name of the program.
    for i in range(1, len(sys.argv)):
        try:
            score_list.append(ft_string_to_int(sys.argv[i]))
        except NoNumber:
            error_list.append(sys.argv[i])
    return score_list, error_list


def ft_print_errores(error_list: list[str]) -> None:
    for param in error_list:
        print("Invalid parameter:", param)


def ft_print_statistics(score_list: list[int]) -> None:
    if len(score_list) == 0:
        print("No scores provided. Usage:",
              "python3 ft_score_analytics.py <score1> <score2> ...")
    else:
        print("Scores processed:", score_list)
        print("Total players:", len(score_list))
        print(f"Average score: {sum(score_list) / len(score_list):.2f}")
        print("High score:", max(score_list))
        print("Low score:", min(score_list))
        print("Range:", max(score_list) - min(score_list))


def main() -> None:
    print("=== Player Score Analytics ===")
    score_list, error_list = ft_process_arguments()
    ft_print_errores(error_list)
    ft_print_statistics(score_list)


if __name__ == "__main__":
    main()
