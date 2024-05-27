#!/usr/bin/python3
"""
Main file for testing
"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values,
    determine the fewest number of
    """
    if total <= 0:
        return 0

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for amount in range(coin, total + 1):
            dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
