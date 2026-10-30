#!/usr/bin/env python3

# Compares two strings and returns True
# if str1 is greater than str2, False otherwise.
def count_vowels(string: str) -> int:
    num_vowels: int = 0

    for char in string:
        if char.lower() in "aeiou":
            num_vowels += 1

    return num_vowels


def is_bigger(str1: str, str2: str) -> bool:
    # Primary sort
    if len(str1) > len(str2):
        return True
    elif len(str1) < len(str2):
        return False
    elif str1.lower() > str2.lower():
        return True
    elif str1.lower() < str2.lower():
        return False
    elif count_vowels(str1) > count_vowels(str2):
        return True
    elif count_vowels(str1) < count_vowels(str2):
        return False

    return False


def cryptic_sorter(strings: list[str]) -> list[str]:
    pos:        int = 0

    while pos < len(strings) - 1:
        if is_bigger(strings[pos], strings[pos + 1]) > 0:
            # Swap
            strings[pos], strings[pos + 1] = strings[pos + 1], strings[pos]
            pos = 0
        else:
            pos += 1

    return strings


if __name__ == "__main__":
    print(cryptic_sorter(["apple", "cat", "banana", "dog", "elephant"]))
    print(cryptic_sorter(["aaa", "bbb", "AAA", "BBB"]))
    print(cryptic_sorter(["hello", "world", "hi", "test"]))
    print(cryptic_sorter([]))
    print(cryptic_sorter([""]))
