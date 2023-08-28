#include "binary_trees.h"

/**
 * binary_tree_size- a function that measures the size of a binary tree
 * @tree: a ptr to the root node of the tree to measure the height
 * Return: size of the tree from current position
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (!tree)
	{
		return (0);
	}
	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}
