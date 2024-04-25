#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Open big gap, and reduce it */
	for (gap = 1; gap < size; gap = gap * 3 + 1)
		;

	/* Insertion sort gap for the gap size */
	for (gap /= 3; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i += 1)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}

		print_array(array, size);
	}
}
