#!/usr/bin/env python3


def count_chars(string: str) -> dict[str, int]:
    result:     dict[str, int] = {}

    for char in string:
        if char in result:
            result[char] += 1
        else:
            result[char] = 1
    return result


def compare_chars(chars1: dict[str, int],
                  chars2: dict[str, int]) -> bool:
    if len(chars1) != len(chars2):
        return False

    for char in chars1:
        if char not in chars2 or \
           chars1[char] != chars2[char]:
            return False

    return True


def string_permutation_checker(s1: str, s2: str) -> bool:
    chars_s1:       dict[str, int]
    chars_s2:       dict[str, int]

    chars_s1 = count_chars(s1)
    chars_s2 = count_chars(s2)

    return compare_chars(chars_s1, chars_s2)


if __name__ == "__main__":
    print(string_permutation_checker("abc", "bca"))
    print(string_permutation_checker("abc", "def"))
    print(string_permutation_checker("listen", "silent"))
    print(string_permutation_checker("hello", "bello"))
    print(string_permutation_checker("", ""))
    print(string_permutation_checker("a", ""))
    print(string_permutation_checker("Abc", "abc"))
    print(string_permutation_checker("a gentleman", "elegant man"))
