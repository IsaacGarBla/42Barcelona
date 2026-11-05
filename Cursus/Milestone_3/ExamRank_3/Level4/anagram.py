#!/usr/bin/env python3


def lower(char: str) -> str:
    if ord(char) >= 65 and ord(char) <= 90:
        return chr(ord(char) + 32)
    return char


def count_letters(string: str) -> dict[str, int]:
    result:     dict[str, int] = {}

    for char in string:
        char = lower(char)
        if char != " ":
            if lower(char) in result:
                result[char] += 1
            else:
                result[char] = 1
    return result


def anagram(s1: str, s2: str) -> bool:
    letters_s1:     dict
    letters_s2:     dict

    letters_s1 = count_letters(s1)
    letters_s2 = count_letters(s2)

    # Check if dict are the same len. If not, return false.
    if len(letters_s1) != len(letters_s2):
        return False

    for key in letters_s1:
        if key not in letters_s2 or \
           letters_s1[key] != letters_s2[key]:
            return False
    return True


if __name__ == "__main__":
    print(anagram("listen", "silent"))
    print(anagram("Dormitory", "Dirty Room"))
    print(anagram("hepllo", "Heqllo"))
