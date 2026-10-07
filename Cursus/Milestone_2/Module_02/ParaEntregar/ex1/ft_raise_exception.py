#!/usr/bin/env python3
# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_raise_exception.py                             :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/05/28 11:50:13 by igarcia-        #+#    #+#               #
#  Updated: 2026/06/08 17:56:22 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def input_temperature(temp_str: str) -> int:
    temp: int

    temp = int(temp_str)
    if temp > 40:
        raise ValueError(f"{temp}°C is too hot for plants (max 40°C)")
    elif temp < 0:
        raise ValueError(f"{temp}°C is too cold for plants (min 0°C)")
    return temp


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
    test_temperature("40")
    test_temperature("0")
    test_temperature("60")
    test_temperature("-10")
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    main()
