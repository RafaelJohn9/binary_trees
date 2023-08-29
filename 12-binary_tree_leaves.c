#include "binary_trees.h"

/**
 * binary_tree_leaves- a function that counts the leaves in a binary tree
 * @tree: a pointer to the root node
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0;

	if (!tree)
	{
		return (0);
	}

	if (!(tree->left) && !(tree->right))
	{
		leaf++;
		return (leaf);
	}
	if (tree->left)
	{
		leaf += binary_tree_leaves(tree->left);
	}
	if (tree->right)
	{
		leaf += binary_tree_leaves(tree->right);
	}
	return (leaf);
}
