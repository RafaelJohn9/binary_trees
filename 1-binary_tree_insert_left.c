#include "binary_trees.h"

/**
 * binary_tree_insert_left- inserts a node on the left branch
 * @parent: this is the parent node
 * @value: the value of the node
 * Return: a binary_tree_t
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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
	child->left = NULL;
	child->right = NULL;

	if (parent->left != NULL)
	{
		parent->left->parent = child;
		child->left = parent->left;

	}
	parent->left = child;
	return (child);
}
