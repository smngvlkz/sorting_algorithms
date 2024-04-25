#include "sort.h"

/**
 * merge - Merges two subarrays of integers
 * @array: The array to be sorted
 * @temp: Temporary array
 * @start: Starting index
 * @mid: Middle index
 * @end: Ending index
 */
void merge(int *array, int *temp, size_t start, size_t mid, size_t end)
{
	size_t left = start, right = mid, i;

	for (i = start; i < end; i++)
	{
		if (left < mid && (right >= end || array[left] <= array[right]))
		{
			temp[i] = array[left];
			left++;
		}
		else
		{
			temp[i] = array[right];
			right++;
		}
	}
}

/**
 * merge_sort_rec - Implements the Merge sort algorithm (recursively)
 * @array: The array to be sorted
 * @temp: Temporary array
 * @start: Starting index
 * @end: Ending index
 */
void merge_sort_rec(int *array, int *temp, size_t start, size_t end)
{
	size_t mid;

	if (end - start <= 1)
		return;

	mid = start + (end - start) / 2;
	merge_sort_rec(array, temp, start, mid);
	merge_sort_rec(array, temp, mid, end);
	merge(array, temp, start, mid, end);

	for (mid = start; mid < end; mid++)
		array[mid] = temp[mid];
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_rec(array, temp, 0, size);

	free(temp);
}
