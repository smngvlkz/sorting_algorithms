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
 * heapify - Builds a heap from a binary tree
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @i: Index of the root
 * @total_size: Size of the array for printing
 */
void heapify(int *array, size_t size, int i, size_t total_size)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < (int)size && array[left] > array[max])
		max = left;

	if (right < (int)size && array[right] > array[max])
		max = right;

	if (max != i)
	{
		swap(&array[i], &array[max]);
		print_array(array, total_size);
		heapify(array, size, max, total_size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		heapify(array, i, 0, size);
	}
}
