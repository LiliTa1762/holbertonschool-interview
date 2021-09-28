#!/usr/bin/python3
"""Rotate it 90 degrees clockwise"""

def rotate_2d_matrix(matrix):
    """Given an n x n 2D matrix, rotate it"""

    x = len(matrix[0])

    for i in range(x - 1, -1, -1):
        for n in range(0, x):
            matrix[n].append(matrix[i].pop(0))
