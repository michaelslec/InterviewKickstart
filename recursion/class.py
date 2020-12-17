#!/bin/python
import time


def capital_combos(problem: str):
    results: list = []
    n: int = len(problem)

    def helper(start: int, slate: str):
        if start == n:
            print(slate)
            results.append(slate)
            # time.sleep(0.003)
        else:
            if not problem[start].isalpha():
                helper(start + 1, slate + problem[start])
            else:
                helper(start + 1, slate + problem[start])
                helper(start + 1, slate + problem[start].upper())

    helper(0, "")

    return results


capital_combos("a1bc")
