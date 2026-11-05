#!/usr/bin/env python3

def locate_digit(string: str, start: int) -> int:
    i:  int = start

    while i < len(string):
        if string[i] in "0123456789":
            return i
        i += 1
    return -1


def pattern_tracker(text: str) -> int:
    pos_first_d:    int
    pos_second_d:   int
    pairs:          int = 0

    pos_first_d = locate_digit(text, 0)
    while pos_first_d != -1:
        pos_second_d = locate_digit(text, pos_first_d + 1)
        if pos_second_d - pos_first_d == 1 and \
           int(text[pos_second_d]) - int(text[pos_first_d]) == 1:
            pairs += 1
        pos_first_d = pos_second_d

    return pairs


if __name__ == "__main__":
    print(pattern_tracker("01234567"))
    print(pattern_tracker("987654321"))
    print(pattern_tracker("1234"))
