#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * getMax - Returns the maximum element from an array
 * @array: The array
 * @size: Size of the array
 * Return: The maximum element
 */
int getMax(int *array, size_t size)
{
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

/**
 * countSort - Sorts the array based on a digit (exp)
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: The digit to sort on (e.g., 1 for LSD, 10 for second LSD, etc.)
 */
void countSort(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};

    for (size_t i = 0; i < size; i++)
    {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (size_t i = 0; i < size; i++)
    {
        array[i] = output[i];
    }

    print_array(array, size);
    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort (LSD)
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    int max = getMax(array, size);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(array, size, exp);
    }
}
