#!/bin/python


def combinations(set):
    solutions = []
    slate = []
    n = len(set)

    def helper(i: int):
        if i == n:
            solutions.append(slate[:])
        else:
            helper(i + 1)
            slate.append(set[i])
            helper(i + 1)
            slate.pop()

    helper(0)
    return solutions


print(combinations([1, 2, 3]))
