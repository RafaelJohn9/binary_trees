#include "binary_trees.h"

/**
 * binary_tree_node- a function that creates a binary tree node
 * @parent: the parent node
 * @value: value of the node
 * Return: a binary_tree_t
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *child;

	child = malloc(sizeof(binary_tree_t));
	if (!child)
	{
		return (NULL);
	}
	child->n = value;
	child->parent = parent;
	child->left = NULL;
	child->right = NULL;
	return (child);
}
