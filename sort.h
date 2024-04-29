#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* PROTOTYPES */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* NEW FUNCTIONS */
int partition(int *array, size_t size, int low, int high);
void quick_sort_rec(int *array, size_t size, int low, int high);
void swap_int(int *a, int *b);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void merge(int *array, int *temp, size_t start, size_t mid, size_t end);
void merge_sort_rec(int *array, int *temp, size_t start, size_t end);


#endif /* SORT_H */
