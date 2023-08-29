#include "binary_trees.h"

bst_t *find_min(bst_t *node);
/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: Pointer to the root node of the tree.
 * @value: Value to be removed from the tree.
 * Return: Pointer to the new root of the tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *minRight;

	if (!root)
	{
		return (root);
	}

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
	}
	else
	{
		if (!root->left)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;
			free(root);

			return (temp);
		}
		minRight = find_min(root->right);
		root->n = minRight->n;

		root->right = bst_remove(root->right, minRight->n);
	}
	return (root);
}

/**
 * find_min - Finds the node with the minimum value in a BST.
 * @node: Root node to start the search from.
 * Return: Pointer to the node with the minimum value.
 */
bst_t *find_min(bst_t *node)
{
	while (node->left)
	{
		node = node->left;
	}
	return (node);
}

