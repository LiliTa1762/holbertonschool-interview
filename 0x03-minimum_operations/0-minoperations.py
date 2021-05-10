#!/usr/bin/python3
"""Method that calculates the fewest
number of operations needed to result
in exactly n H characters"""


def minOperations(n):
    """Method of minimum operation"""
    if n <= 0:
        return 0

    if n <= 4:
        return n

    if n % 2 == 0:
        x = int((n / 2) + 1)
        return x

    else:
        x = int((n / 2) + 2)
        return x
