#!/bin/python
import time


def capital_combos(problem: str):
    results: list = []
    n: int = len(problem)

    def helper(start: int, slate: str):
        if start == n:
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


def capital_combos_mutable(problem: str):
    results = []
    slate = []
    n = len(problem)

    def helper(start: int):
        if start == n:
            results.append("".join(slate))
            # time.sleep(0.003)
        else:
            if not problem[start].isalpha():
                slate.append(problem[start])
                helper(start + 1)
                slate.pop(-1)
            else:
                slate.append(problem[start])
                helper(start + 1)
                slate.pop(-1)

                slate.append(problem[start].upper())
                helper(start + 1)
                slate.pop(-1)

    helper(0)

    return results


start = time.time()
capital_combos("abcdefghiklmnopqrstuv")
end = time.time()
print(f"immutable: {end - start}")

start = time.time()
capital_combos_mutable("abcdefghiklmnopqrstuv")
end = time.time()
print(f"mutable: {end - start}")
