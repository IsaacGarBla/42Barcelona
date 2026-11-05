#!/usr/bin/env python3


def shadow_merge(list1: list[int], list2: list[int]) -> list[int]:
    result:     list[int] = []
    index_l1:   int = 0
    index_l2:   int = 0

    while index_l1 < len(list1) and index_l2 < len(list2):
        if list1[index_l1] <= list2[index_l2]:
            result += [list1[index_l1]]
            index_l1 += 1
        else:
            result += [list2[index_l2]]
            index_l2 += 1

    while index_l1 < len(list1):
        result += [list1[index_l1]]
        index_l1 += 1

    while index_l2 < len(list2):
        result += [list2[index_l2]]
        index_l2 += 1

    return result


if __name__ == "__main__":
    print(shadow_merge([1, 3, 5], [2, 4, 6]))
    print(shadow_merge([1, 2, 3], [4, 5, 6]))
    print(shadow_merge([1], [2, 3, 4]))
    print(shadow_merge([], [1, 2, 3]))
    print(shadow_merge([1, 1, 2], [1, 3, 3]))
