#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the doubly linked list
 * @node1: The first node to swap
 * @node2: The second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	node2->next = node1;
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = *list;
	while (swapped)
	{
		swapped = 0;
		while (node->next != NULL)
		{
			if (node->n > node->next->n)
			{
				swap_nodes(list, node, node->next);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
				node = node->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		while (node->prev != NULL)
		{
			if (node->n < node->prev->n)
			{
				swap_nodes(list, node->prev, node);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
				node = node->prev;
		}
	}
}
