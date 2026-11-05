#!/usr/bin/env python3

def mirror_list(lst: list[int]) -> list[int]:
    result:     list[int] = []

    for each in range(len(lst)-1, -1, -1):
        result.append(lst[each])
    return result


def mirror_matrix(matrix: list[list[int]]) -> list[list[int]]:
    result:     list[list[int]] = []

    for each in matrix:
        result.append(mirror_list(each))
    return result


if __name__ == "__main__":
    print("Mirror [[1,2,3],[4,5,6]]:",
          mirror_matrix([[1, 2, 3], [4, 5, 6]]))
    print("Mirror [[1,2],[3,4],[5,6]]:",
          mirror_matrix([[1, 2], [3, 4], [5, 6]]))
    print("Mirror [[7]]:",
          mirror_matrix([[7]]))
    print("Mirror [[1,2,3,4]]:",
          mirror_matrix([[1, 2, 3, 4]]))
    print("Mirror [[-1,-2],[-3,-4]]:",
          mirror_matrix([[-1, -2], [-3, -4]]))
