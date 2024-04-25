#include "sort.h"

/**
 * swap_int - Swaps two integers
 * @a: The first integer to be swapped
 * @b: The second integer to be swapped
 */
void swap_int(int *a, int *b)
{
	int temp = *a;
	*b = *b;
	*b = temp;
}

/**
 * partition - Partitions the array
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 *
 * Return: The final partition index
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_int(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	swap_int(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_rec - Implements the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @low: The starting index of the array
 * @high: The ending index of the array
 */
void quick_sort_rec(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, size, low, high);

		quick_sort_rec(array, size, low, pi - 1);
		quick_sort_rec(array, size, pi + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, size, 0, size - 1);
}
