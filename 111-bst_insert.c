#include "binary_trees.h"

/**
 * bst_insert- inserts a value in a binary search tree
 * @tree:  a double ptr to the root node of the BST to insert the value
 * @value: the value to be inserted
 * Return: pointer to the node inserted
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *child, **temp;

	temp = tree;
	child = NULL;
	if (!tree || !(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return NULL;
		return (*tree);
	}

	if (value > (*temp)->n)
	{
		if ((*temp)->right)
		{
			child = bst_insert(&((*temp)->right), value);
		}
		else
		{
			(*temp)->right = binary_tree_node(*temp, value);
			child = (*temp)->right;
		}
		return (child);
	}
	else if (value < (*temp)->n)
	{
		if ((*temp)->left)
		{
			child = bst_insert(&((*temp)->left), value);
		}
		else
		{
			(*temp)->left = binary_tree_node(*temp, value);
			child = (*temp)->left;
		}
		return (child);
	}
	return (NULL);
}
