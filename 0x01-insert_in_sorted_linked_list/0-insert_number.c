#include "lists.h"

/**
 * insert_node - function to add a node at the beginning
 * @head: pointer to the first node of a list
 * @number: const variable
 * Return: the address of the new node, or NULL if it failed
*/
listint_t *insert_node(listint_t **head, int number)
{

	listint_t *current= NULL;
	listint_t *new= NULL;

	if ((*head) == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n= number;
	current= (*head);

	if ((*head)->next == NULL)
	{
		if ((*head)->n >= number)
		{
			(*head) = new->next;
			(*head) = new;
		}
		else {
			(*head)->next = new;
			return (new);
		}
	}

	while (current->next != NULL)
	{
		if (current->next->n >= number)
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		else {
			current = current->next;
		}
	}

	if (current->next == NULL)
	{
		if (current->n <= number)
		{
			current->next = new;
			new->next = NULL;
		}
		
		else {
			new->next = current;
		}
	}
	return (new);
}
