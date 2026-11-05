#!/etc/bin/env pytho3

def locate(char: str, string: str, start: int) -> int:
    i:  int = start

    while i < len(string):
        if string[i] == char:
            return i
        i += 1
    return -1


def hidenp(small: str, big: str) -> bool:
    start:      int = 0
    located:    int

    for char in small:
        located = locate(char, big, start)
        if located == -1:
            return False
        else:
            start = located + 1
    return True


if __name__ == "__main__":
    print("Hiden 'abc' in 'a1b2c3': ", hidenp("abc", "a1b2c3"))
    print("Hiden 'ace' in 'abcde': ", hidenp("ace", "abcde"))
    print("Hiden 'aec' in 'abcde': ", hidenp("aec", "abcde"))
    print("Hiden '' in 'abc': ", hidenp("", "abc"))
    print("Hiden 'abc' in 'ab': ", hidenp("abc", "ab"))
    print("Hiden 'aaaa' in 'aaa': ", hidenp("aaaa", "aaa"))
    print("Hiden 'sing' in 'ubsequence testing: ",
          hidenp("sing", "ubsequence testing"))
