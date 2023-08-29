#include "binary_trees.h"

/**
 * bst_search- searches for a value in a binary search tree
 * @tree: node of the tree
 * @value: int value to be searched
 * Return: a pointer to the node found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
	{
		return (NULL);
	}

	if (value < tree->n)
	{
		return (bst_search(tree->left, value));
	}
	else if (value > tree->n)
	{
		return (bst_search(tree->right, value));
	}
	else
	{
		return ((bst_t *)tree);
	}
}
