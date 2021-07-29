
#include "binary_trees.h"


/**
 * add_tree_node - Creates a binary tree node
 * @parent: Parent node
 * @value: Value of node
 * Return: Create new Binary tree
 */
binary_tree_t *add_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

/**
* insert_sorted_array - Inserts sorted array to a Binary Tree
* @array: Pointer to first element of sorted array
* @min: Minimum value
* @max: Maximum Value
* Return: Pointer to root node of AVL Tree or Null
*/
avl_t *insert_sorted_array(int *array, int min, int max)
{
	int average;
	avl_t *tree;
	binary_tree_t *parent = NULL;

	if (min > max)
		return (NULL);

	average = (min + max) / 2;

	tree = add_tree_node(parent, array[average]);

	if (tree == NULL)
		return (NULL);

	tree->left = insert_sorted_array(array, min, average - 1);
	tree->right = insert_sorted_array(array, average + 1, max);

	if (tree->left)
		tree->left->parent = tree;

	if (tree->right)
		tree->right->parent = tree;

	return (tree);
}

/**
* sorted_array_to_avl - Builds an AVL Tree from a sorted array
* @array: Pointer to first element of sorted array
* @size: Number of elements in array
* Return: Pointer to root node of AVL Tree, or Null on failure
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array == NULL)
		return (NULL);

	root = insert_sorted_array(array, 0, size - 1);

	return (root);
}
