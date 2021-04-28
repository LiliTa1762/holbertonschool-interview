#include "lists.h"
/**
 * insert_node - function to add a node in a SLL
 * @head: pointer to the first node of a list
 * @number: const variable
 * Return: the address of the new node, or NULL if it failed
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current, *new = NULL;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;

	current = *head;
	if (*head == NULL)
	{
		*head = new, new->next = NULL;
		return (new);
	}

	if (current->next == NULL)
	{
		new->next = NULL, current->next = new;
		return (new);
	}

	if (number <= current->n)
	{
		new->next = current, *head = new;
		return (new);
	}

	while (current->next != NULL)
	{
		if (number <= current->next->n)
		{
			new->next = current->next, current->next = new;
			return (new);
		}
		current = current->next;
	}
	current->next = new, new->next = NULL;
	return (new);
}
