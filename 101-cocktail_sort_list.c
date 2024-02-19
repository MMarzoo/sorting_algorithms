#include "sort.h"
#include <stdio.h>
/**
 *swap_node - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *old = node->prev, *current = node;

	old->next = current->next;
	if (current->next)
		current->next->prev = old;
	current->next = old;
	current->prev = old->prev;
	old->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
/**
 *cocktail_sort_list - this is a cocktail sort implementation
 *working on a double linked lists
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap = 1;

	if (!list || !(*list) || !(*list)->next)
		return;
	node = *list;
	while (swap == 1)
	{
		swap = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				swap = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swap == 0)
			break;
		swap = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				swap = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
