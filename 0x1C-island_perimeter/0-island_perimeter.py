#!/usr/bin/python3
"""
Returns the perimeter of
the island described in grid
"""


def island_perimeter(grid):
    """
    Grid is a list of list of integers.
    The grid is completely surrounded by water.
    There is only one island (or nothing).
    The island doesn’t have “lakes” (water 
    inside that isn’t connected to the water
     surrounding the island).  
    """
    perimeter = 0
    x = len(grid)
    y = len(grid[0])
    for i in range(x):
        for j in range(y):
            if(grid[i][j] == 1):
                if(i == 0 or grid[i-1][j] == 0):
                    perimeter = perimeter + 1
                if(i == x-1 or grid[i+1][j] == 0):
                    perimeter = perimeter + 1
                if(j == 0 or grid[i][j-1] == 0):
                    perimeter = perimeter + 1
                if(j == y-1 or grid[i][j+1] == 0):
                    perimeter = perimeter + 1
    return perimeter
