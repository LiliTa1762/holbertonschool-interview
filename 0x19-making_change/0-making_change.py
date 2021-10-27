#!/usr/bin/python3

"""
Determine the fewest number
of coins needed to meet a given amount
"""


def makeChange(coins, total):
    """
    Return: fewest number of coins needed to meet total
    """
    if total <= 0:
        return 0

    placeholder = total + 1

    values = {0: 0}

    for i in range(1, total + 1):
        values[i] = placeholder

        for coin in coins:
            current = i - coin
            if current < 0:
                continue

            values[i] = min(values[current] + 1, values[i])

    if values[total] == total + 1:
        return -1

    return values[total]
