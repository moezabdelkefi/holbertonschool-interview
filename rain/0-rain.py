def rain(walls):
    if not walls or len(walls) < 3:
        return 0

    water = 0
    size = len(walls)

    left_max = [0] * size
    right_max = [0] * size

    left_max[0] = walls[0]
    for i in range(1, size):
        left_max[i] = max(left_max[i - 1], walls[i])

    right_max[size - 1] = walls[size - 1]
    for i in range(size - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    for i in range(size):
        water += min(left_max[i], right_max[i]) - walls[i]

    return water


# Test cases
if __name__ == "__main__":
    walls1 = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls1))  # Output: 6

    walls2 = [2, 0, 0, 4, 0, 0, 1, 0]
    print(rain(walls2))  # Output: 6
