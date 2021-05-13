#!/usr/bin/python3
"""Method that calculates the fewest
number of operations needed to result
in exactly n H characters"""


def minOperations(n):
    """Method of minimum operation"""
    if type(n) != int or n <= 0:
        return 0

    if n <= 4:
        return n

    result = 0
    i = 2
    while i <= n:
        if n % i == 0:
            result += i
            n = n / i
            i = i - 1
        i = i + 1
    return int(result)
