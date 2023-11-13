#!/usr/bin/python3
"""
N queens
"""
import sys


def is_safe(board, row, col):
    return all(board[i] != col and
               board[i] - i != col - row and
               board[i] + i != col + row
               for i in range(row))


def solve_nqueens(board, row, n, solutions):
    if row == n:
        solutions.append(list(enumerate(board)))
        return
    for col in range(n):
        if is_safe(board, row, col):
            board[row] = col
            solve_nqueens(board, row + 1, n, solutions)


def nqueens(n):
    if not isinstance(n, int) or n < 4:
        print("Usage: nqueens N\nN must be a number greater or equal to 4")
        sys.exit(1)

    board = [-1] * n
    solutions = []
    solve_nqueens(board, 0, n, solutions)

    for sol in solutions:
        print(sol)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    nqueens(N)
