#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int i, max = 0, *count, *sorted;

	if (array == NULL || size < 2)
		return;

	/* maximum element to be found in the array */
	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	/* initialize the array with all zeros */
	count = malloc(sizeof(int) * (max + 1));
	for (i = 0; i <= max; i++)
		count[i] = 0;

	/* store count for each element */
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	/* build output sorted array */
	sorted = malloc(sizeof(int) * size);
	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* copy the sorted array to the original */
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(count);
	free(sorted);
}
