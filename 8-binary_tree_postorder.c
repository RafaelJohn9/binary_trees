#include "binary_trees.h"

/**
 * binary_tree_postorder- goes through a binary tree using in-order traversal
 * @tree: a ptr to the root node of the tree to traverse
 * @func: a function ptr
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
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
		binary_tree_postorder(tree->left, func);
	}
	if (tree->right)
	{
		binary_tree_postorder(tree->right, func);
	}
	func(tree->n);
}
