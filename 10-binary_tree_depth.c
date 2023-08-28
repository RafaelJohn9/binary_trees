#include "binary_trees.h"

/**
 * binary_tree_depth- a function that measures the depthof a binary tree
 * @tree: a ptr to the root node of the tree to measure the height
 * Return: size of the tree from current position
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t parent_depth;

	if (!tree)
	{
		return (0);
	}

	if (!(tree->parent))
	{
		return (0);
	}

	parent_depth = binary_tree_depth(tree->parent);

	return (parent_depth + 1);
}
