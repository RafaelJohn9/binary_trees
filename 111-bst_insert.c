#include "binary_trees.h"

/**
 * bst_insert- inserts a value in a binary search tree
 * @tree:  a double ptr to the root node of the BST to insert the value
 * @value: the value to be inserted
 * Return: pointer to the node inserted
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *child

	if (!tree)
	{
		child = malloc(sizeof(bst_t));
		child->n = value;
		child->parent = NULL;
		child->left = NULL;
		child->right = NULL;
	}
}
