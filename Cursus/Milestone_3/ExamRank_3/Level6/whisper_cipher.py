#!/usr/bin/env python3

def is_alphabetit(char: str) -> bool:
    return (ord(char) >= 65 and ord(char) <= 90) or \
           (ord(char) >= 97 and ord(char) <= 122)


def is_lower(char: str) -> bool:
    return char in "abcdefghijklmnopqrstuvwxyz"


def shift_char(char: str, shift: int) -> str:
    tmp:    int

    tmp = ord(char) + shift
    if is_lower(char):
        if tmp > 122:
            tmp = 97 + (tmp - 122 - 1)
        elif tmp < 97:
            tmp = 122 - (97 - tmp - 1)
    elif tmp > 90:
        tmp = 65 + (tmp - 90 - 1)
    elif tmp < 65:
        tmp = 90 - (65 - tmp - 1)
    return chr(tmp)


def whisper_cipher(text: str, shift: int) -> str:
    tmp:    str = ""

    for char in text:
        if is_alphabetit(char):
            tmp += shift_char(char, shift)
        else:
            tmp += char
    return tmp


if __name__ == "__main__":
    print(whisper_cipher("hello", 3))
    print(whisper_cipher("Hello World!", 1))
    print(whisper_cipher("xyz", 3))
    print(whisper_cipher("ABC123def", 5))
    print(whisper_cipher("", 10))
    print(whisper_cipher("abc", -3))
