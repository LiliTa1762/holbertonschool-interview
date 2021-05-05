#include "binary_trees.h"

/**
 * binary_tree_node - function to add a node in a BT
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: return a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	node = malloc(sizeof(binary_tree_t));
		if (node == NULL)
			return (NULL);

	node->n = value;
	node->parent = parent;

		return (node);
}
