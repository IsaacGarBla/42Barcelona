#!/usr/bin/env python3

def number_base_converter(number: str, from_base: int, to_base: int) -> str:
    result:     str = ""
    value:      int
    negative:   bool = False
    digits:     str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    # Validamos la base
    if from_base not in range(2, 37) or \
       to_base not in range(2, 37):
        return "ERROR"
    try:
        value = int(number, base=from_base)
    except ValueError:
        return "ERROR"

    if value < 0:
        negative = True
        value *= -1

    while value >= to_base:
        result = digits[value % to_base] + result
        value = value // to_base

    if value != 0:
        result = digits[value] + result

    if negative:
        result = "-" + result

    return result


if __name__ == "__main__":
    print(number_base_converter("-1010", 2, 8))
    print(number_base_converter("35", 10, 36))
