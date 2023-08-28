#include "binary_trees.h"

/**
 * binary_tree_insert_right- a funtion that inserts a node as the right child of another node
 * @parent: the parent node
 * @value: the value of the new node
 * Return: returns a pointer to the child node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *child;

	if (!parent)
	{
		return (NULL);
	}

	child = malloc(sizeof(binary_tree_t));
	if (!child)
	{
		return (NULL);
	}
	child->n = value;
	child->parent = parent;
	child->right = NULL;
	child->left = NULL;

	if (parent->right != NULL)
	{
		parent->right->parent = child;
		child->right = parent->right;

	}
	parent->right = child;
	return (child);
}
