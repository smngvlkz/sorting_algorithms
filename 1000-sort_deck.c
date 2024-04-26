#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * card_cmp - Compares two cards
 * @card1: The first card
 * @card2: The second card
 *
 * Return: Negative number if card1 < card2, 0 if equal, positive number if card1 > card2
 */
int card_cmp(const void *card1, const void *card2)
{
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
	deck_node_t **_card1 = (deck_node_t **)card1;
	deck_node_t **_card2 = (deck_node_t **)card2;
	int i, value1, value2;

	if ((*_card1)->card->kind < (*_card2)->card->kind)
		return (-1);
	if ((*_card1)->card->kind > (*_card2)->card->kind)
		return (1);

	for (i = 0; i < 13; i++)
	{
		if (!strcmp(values[i], (*_card1)->card->value))
			value1 = i;
		if (!strcmp(values[i], (*_card2)->card->value))
			value2 = i;
	}

	return (value1 - value2);
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: The deck to sort
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t **array, *node;
	size_t i = 0, size = 0;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	node = *deck;
	while (node != NULL)
	{
		size++;
		node = node->next;
	}

	array = malloc(sizeof(*array) * size);
	if (array == NULL)
		return;

	node = *deck;
	while (node != NULL)
	{
		array[i++] = node;
		node = node->next;
	}

	qsort(array, size, sizeof(deck_node_t *), card_cmp);

	for (i = 0; i < size - 1; i++)
	{
		array[i]->next = array[i + 1];
		array[i + 1]->prev = array[i];
	}
	array[0]->prev = NULL;
	array[size - 1]->next = NULL;
	*deck = array[0];

	free(array);
}
