#!/usr/bin/env python3

def bracket_validator1(s: str) -> bool:
    i:             int
    brackets:      list[list[int]]

    i = 0
    brackets = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

    while (i < len(s)):
        match s[i]:
            case "[":
                if brackets[0][0] == 0:
                    brackets[0][1] = brackets[1][0]
                    brackets[0][2] = brackets[2][0]
                brackets[0][0] += 1
            case "]":
                brackets[0][0] -= 1
                if brackets[0][0] < 0 or (brackets[0][0] == 0 and
                   (brackets[0][1] != brackets[1][0]
                   or brackets[0][2] != brackets[2][0])):
                    return False
            case "{":
                if brackets[1][0] == 0:
                    brackets[1][1] = brackets[0][0]
                    brackets[1][2] = brackets[2][0]
                brackets[1][0] += 1
            case "}":
                brackets[1][0] -= 1
                if brackets[1][0] < 0 or (brackets[1][0] == 0 and
                   (brackets[1][1] != brackets[0][0]
                   or brackets[1][2] != brackets[2][0])):
                    return False
            case "(":
                if brackets[2][0] == 0:
                    brackets[2][1] = brackets[0][0]
                    brackets[2][2] = brackets[1][0]
                brackets[2][0] += 1
            case ")":
                brackets[2][0] -= 1
                if brackets[2][0] < 0 or (brackets[1][0] == 0 and
                   (brackets[2][1] != brackets[0][0]
                   or brackets[2][2] != brackets[1][0])):
                    return False
        i += 1
    return (brackets[0][0] == 0
            and brackets[1][0] == 0 and brackets[2][0] == 0)


def bracket_validator(s: str) -> bool:
    mapping:    dict = {")": "()", "}": "{", "]": "["}
    top:        str
    stack:      list = []

    for char in s:
        if char in mapping:
            top = stack.pop() if len(stack) > 0 else '*'
            if mapping[char] != top:
                return False
        elif char in mapping.values():
            stack.append(char)
    return len(stack) == 0


if __name__ == "__main__":
    print("()", bracket_validator("()"))
    print("()[]{}", bracket_validator("()[]{}"))
    print("(]", bracket_validator("(]"))
    print("([)]", bracket_validator("([)]"))
    print("{[]}", bracket_validator("{[]}"))
    print("hello(world)", bracket_validator("hello(world)"))
    print("((())", bracket_validator("((())"))
    print("", bracket_validator(""))
