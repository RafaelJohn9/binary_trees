#include "binary_trees.h"

/* Helper function to find the leftmost node (in-order successor) */
static bst_t *find_min(bst_t *node);

/**
 * bst_remove - removes a node from a binary search tree
 * @root: a pointer to the root node of the tree
 * @value: the value of the node to be removed
 *
 * Return: a pointer to the new root node after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
		bst_t *temp;

	if (!root)
		return (NULL); /* Value not found */

	/* Search for the node to be deleted */
	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
	}
	else /* Node with the value to be deleted found */
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

		/* Node with two children, find the in-order successor */
		temp = find_min(root->right);

		/* Copy the in-order successor's content to this node */
		root->n = temp->n;

		/* Delete the in-order successor */
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}

/**
 * find_min- finds the min node
 * @node: node pointer
 * Return: ptr
 */
static bst_t *find_min(bst_t *node)
{
	while (node->left)
	{
		node = node->left;
	}
	return (node);
}
