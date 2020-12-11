#!/bin/python


def combinations(set, slate=""):
    # print(set)
    if len(set) == 0:
        print(slate)
    else:
        combinations(set[1:], slate + str(set[0]))
        combinations(set[1:], slate)


combinations([1, 2, 3])
