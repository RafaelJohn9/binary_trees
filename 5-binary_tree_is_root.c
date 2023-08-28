#include "binary_trees.h"

/**
 * binary_tree_is_root- a function that checks if a given node is a root
 * @node: node checked if its root
 * Return: 0 if false 1 if true
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
	{
		return (0);
	}

	if (!(node->parent))
	{
		return (1);
	}
	return (0);
}
