#!/bin/python3


def binary_string(n, bin_str=""):
    if n == 0:
        print(bin_str)
        return
    for i in range(0, 2):
        new_str = bin_str + str(i)
        binary_string(n - 1, new_str)


binary_string(2)
