#!/bin/python3


def binary_string(n, slate=""):
    if n == 0:
        print(slate)
    else:
        for i in range(0, 10):
            binary_string(n - 1, slate + str(i))


binary_string(12)
