#!/bin/python


def perm_no_rep(choices, slate=""):
    if len(choices) == 0:
        print(slate)
    else:
        for i in range(len(choices)):
            perm_no_rep(choices[:i] + choices[i + 1 :], slate + choices[i])


perm_no_rep(["a", "b", "c", "d"])
