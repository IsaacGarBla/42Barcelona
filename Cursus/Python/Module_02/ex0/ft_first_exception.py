#!/usr/bin/env python3
# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_first_exception.py                             :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarcia- <igarcia-@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/28 10:54:10 by igarcia-        #+#    #+#               #
#  Updated: 2026/05/28 14:11:00 by igarcia-        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def test_temperature(temp_str: str) -> None:
    temp: int
    print("Input data is '", temp_str, "'", sep="")
    try:
        temp = input_temperature(temp_str)
        print("Temperature is now ", temp, "°C\n", sep="")
    except ValueError as error:
        print(f"Caught input_temperature error: {error}\n")


def main() -> None:
    print("=== Garden Temperature ===\n")
    test_temperature("25")
    test_temperature("abc")
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    main()
