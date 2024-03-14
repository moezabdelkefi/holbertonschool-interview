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
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
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
	size_t i;
	int j;

	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}

	for (j = 1; j < 10; j++)
	{
		count[j] += count[j - 1];
	}

	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / exp) % 10] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in a
 * scending order using Radix sort (LSD)
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int exp;

	if (array == NULL || size < 2)
		return;

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
	}
}
