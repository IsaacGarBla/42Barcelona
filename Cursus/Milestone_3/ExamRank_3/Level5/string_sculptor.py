#!/usr/bin/env python3


def lower(char: str) -> str:
    if ord(char) >= 65 and ord(char) <= 90:
        return chr(ord(char) + 32)
    return char


def upper(char: str) -> str:
    if ord(char) >= 97 and ord(char) <= 122:
        return chr(ord(char) - 32)
    return char


def is_alphabetit(char: str) -> bool:
    return (ord(char) >= 65 and ord(char) <= 90) or \
           (ord(char) >= 97 and ord(char) <= 122)


def string_sculptor(text: str) -> str:
    result:     str = ""
    pair:        bool = False

    for char in text:
        if is_alphabetit(char):
            if pair:
                result += upper(char)
            else:
                result += lower(char)
            pair = not pair
        else:
            result += char
    return result


if __name__ == "__main__":
    print(string_sculptor("hello"))
    print(string_sculptor("Hello World"))
    print(string_sculptor(" hello "))
    print(string_sculptor("abc123def"))
    print(string_sculptor("Python3.9!"))
    print(string_sculptor(""))
