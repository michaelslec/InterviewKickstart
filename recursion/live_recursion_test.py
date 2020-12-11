#!/bin/python


def check_if_sum_possible(arr, k):
    length = len(arr)

    def helper(idx, remaining, picked):
        if remaining == 0 and picked:
            return True
        if idx >= length:
            return picked and remaining == 0
        return helper(idx + 1, remaining, picked) or helper(
            idx + 1, remaining - arr[idx], True
        )

    return helper(0, k, False)


print(check_if_sum_possible([8, -11], 8))
