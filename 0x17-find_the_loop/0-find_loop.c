#include "lists.h"
#include <stdio.h>
/**
 * find_listint_loop - finds the loop in a LL
 * @head: pointer to the head of LL
 *
 * Return: address of the node where the loop starts, or NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *current, *prev;

	if (!head)
		return (NULL);

	current = prev = head;

	while (prev && current && current->next)
	{
		prev = prev->next;
		current = (current->next)->next;
		if (current == prev)
		{
			prev = head;

			while (1)
			{
				if (prev == current)
					return (prev);

				prev = prev->next;
				current = current->next;
			}
		}
	}

	return (NULL);
}
