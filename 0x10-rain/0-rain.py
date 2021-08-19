#!/usr/bin/python3
"""
Calculate how many square units
of water will be retained after
it rains
"""

def rain(walls):
    """walls is a list of non-negative integers"""
    if walls is None:
        return 0
    index_left = 0
    index_right = len(walls) - 1
    max_left = 0
    max_right = 0
    water = 0
    while (index_left <= index_right):
        max_left = max(max_left, walls[index_left])
        max_right = max(max_right, walls[index_right])
        if max_left < max_right:
            water += max_left - walls[index_left]
            index_left += 1
        else:
            water += max_right - walls[index_right]
            index_right -= 1
    return water
