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

	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		return (new);
	}

	current = (*head);
	if (current->next == NULL)
	{
		if (current->n >= number)
			current = new->next, current = new;
	}
	while (current->next != NULL)
	{
		if (current->next->n >= number)
		{
			new->next = current->next, current->next = new;
			return (new);
		}
		else
			current = current->next;
	}
	if (current->next == NULL)
	{
		if (current->n <= number)
			current->next = new, new->next = NULL;
		else
			new->next = current;
	}
	return (new);
}
