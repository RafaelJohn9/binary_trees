#include "binary_trees.h"

/**
 * binary_tree_preorder- goes through a binary tree using pre-order traversal
 * @tree: the tree to be transversed
 * @func: a pointer to a funtion to call for each node
 * Return: none
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
	{
		return;
	}

	if (!(tree->left) && !(tree->right))
	{
		func(tree->n);
		return;
	}

	if (tree->left)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
	}
	if (tree->right)
	{
		if (!tree->left)
		{
			func(tree->n);
		}
		binary_tree_preorder(tree->right, func);
	}
}
