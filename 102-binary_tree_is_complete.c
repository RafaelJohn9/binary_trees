#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_complete_recursive(tree, 0, binary_tree_size(tree)));
}

/**
 * is_complete_recursive - Recursive helper function
 * @tree: Pointer to the root node of the tree.
 * @index: Index of the current node.
 * @size: Total number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete_recursive(const binary_tree_t *tree, int index, int size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, size) &&
    is_complete_recursive(tree->right, 2 * index + 2, size));
}