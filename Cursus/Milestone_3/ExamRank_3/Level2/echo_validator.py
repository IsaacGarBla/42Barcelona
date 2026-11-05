#!/usr/bin/env python2

def lower(string: str) -> str:
    result: str = ""

    for char in string:
        if ord(char) >= 65 and ord(char) <= 90:
            result += chr(ord(char) + 32)
        else:
            result += char
    return result


def is_alphabetic(char: str) -> bool:
    return lower(char) in "abcdefghijklmnopqrstuvwxyz"


def reverse(string: str) -> str:
    result:     str = ""

    for char in string:
        result = char + result

    return result


def only_alphabet(string: str) -> str:
    result: str = ""

    for char in string:
        if is_alphabetic(char):
            result += char

    return result


def echo_validator(text: str) -> bool:
    string_alp = lower(only_alphabet(text))

    return string_alp == reverse(string_alp)


if __name__ == "__main__":
    print("racecar: ", echo_validator("racecar"))
    print("A man a plan a canal Panama: ",
          echo_validator("A man a plan a canal Panama"))
    print("race a car: ", echo_validator("race a car"))
    print("Was it a car or a cat I saw: ",
          echo_validator("Was it a car or a cat I saw"))
    print("hello: ", echo_validator("hello"))
    print("Madam Im Adam", echo_validator("Madam Im Adam"))
    print("Madam", echo_validator("Madam"))
