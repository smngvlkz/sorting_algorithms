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
 * hoare_partition - Orders a subset of an array of integers according to
 * the Hoare partition scheme
 * @array: The array of integers
 * @size: The number of elements in @array
 * @low: The lowest index of the subset to order
 * @high: The highest index of the subset to order
 *
 * Return: The final partition index
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_hoare_recursion - Implements the quicksort algorithm through
 * recursion
 * @array: The array to sort
 * @size: The size of the array
 * @low: The lowest index of the partition to sort
 * @high: The highest index of the partition to sort
 */
void quick_sort_hoare_recursion(int *array, size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = hoare_partition(array, size, low, high);
		quick_sort_hoare_recursion(array, size, low, pi);
		quick_sort_hoare_recursion(array, size, pi + 1, high);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_hoare_recursion(array, size, 0, size - 1);
}