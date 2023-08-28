#include "binary_trees.h"

/**
 * binary_tree_is_leaf- a function that checks if a node is a leaf
 * @node: a this is a node pointer
 * Return: 0 for false 1 for true
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
	{
		return (0);
	}
	if (!(node->left) && !(node->right))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
