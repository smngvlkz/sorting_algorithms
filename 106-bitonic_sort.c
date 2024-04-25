#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: The first integer to be swapped
 * @b: The second integer to be swapped
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_compare - Compares and sorts two numbers in bitonic sequence
 * @up: Determines the sorting direction
 * @array: The array to be sorted
 * @i: Starting index of the sequence
 * @j: Size of the sequence
 */
void bitonic_compare(int up, int *array, size_t i, size_t j)
{
	if ((array[i] > array[j]) == up)
		swap(&array[i], &array[j]);
}

/**
 * bitonic_merge - Merges two bitonic sequences
 * @up: Determines the sorting direction
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bitonic_merge(int up, int *array, size_t size)
{
	size_t k, i;

	k = size / 2;

	if (size < 2)
		return;

	for (i = 0; i < k; i++)
		bitonic_compare(up, array, i, i + k);

	bitonic_merge(up, array, k);
	bitonic_merge(up, array + k, k);
}

/**
 * bitonic_sort_seq - Generates a bitonic sequence
 * @up: Determines the sorting direction
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bitonic_sort_seq(int up, int *array, size_t size)
{
	size_t k;

	k = size / 2;

	if (size < 2)
		return;

	bitonic_sort_seq(1, array, k);
	bitonic_sort_seq(0, array + k, k);

	bitonic_merge(up, array, size);
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_seq(1, array, size);
}
