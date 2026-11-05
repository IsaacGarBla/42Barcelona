#!/usr/bin/env python3

"""
Returns a string with the characters that appear
in both strings, without repetitions.
Characters are added in the order they appear in the first string.
"""


def inter(s1: str, s2: str) -> str:
    result:     str = ""

    for char in s1:
        if char in s2 and char not in result:
            result += char
    return result


if __name__ == "__main__":
    print(inter("hello", "world"))
    print(inter("banana", "band"))
    print(inter("abcabc", "bc"))
    print(inter("abc", "xyz"))
    print(inter("", "abc"))
