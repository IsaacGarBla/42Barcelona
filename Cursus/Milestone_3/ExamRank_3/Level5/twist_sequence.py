#!//usr/bin/env python3


def twist_sequence(arr: list[int], k: int) -> list[int]:

    for i in range(0, k):
        arr = arr[-1:] + arr[0:-1]
    return arr


if __name__ == "__main__":
    print(twist_sequence([1, 2, 3, 4, 5], 2))
    print(twist_sequence([1, 2, 3], 1))
    print(twist_sequence([1, 2, 3, 4], 0))
    print(twist_sequence([1, 2, 3], 5))
    print(twist_sequence([], 3))
