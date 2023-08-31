#include "binary_trees.h"

/**
 * rebalance - Rebalances the tree if necessary after insertion.
 * @tree: Double pointer to the root of the tree.
 * @node: Node that was just inserted.
 */
void rebalance(avl_t **tree, avl_t *node)
{
	avl_t *parent;
	int balance;

	while (node && node->parent)
	{
		parent = node->parent;
		balance = binary_tree_balance(node);
		if (balance > 1 && binary_tree_balance(parent) > 0)
		{
			*tree = binary_tree_rotate_right(parent);
			break;
		}
		else if (balance < -1 && binary_tree_balance(parent) < 0)
		{
			*tree = binary_tree_rotate_left(parent);
			break;
		}
		else if (balance < -1 && binary_tree_balance(parent) > 0)
		{
			node = binary_tree_rotate_left(parent);
			*tree = binary_tree_rotate_right(node->parent);
			break;
		}
		else if (balance > 1 && binary_tree_balance(parent) < 0)
		{
			node = binary_tree_rotate_right(parent);
			*tree = binary_tree_rotate_left(node->parent);
			break;
		}
		else
			node = parent;
	}
}

/**
 * avl_insert - Inserts a node into an AVL tree while maintaining balance.
 * @tree: Double pointer to the root of the tree.
 * @value: Value to be inserted.
 * Return: Pointer to the new node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node, *parent, *new_node;

	if (!tree)
		return (NULL);
	node = *tree;
	parent = NULL;
	while (node)
	{
		parent = node;
		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
		else
			return (NULL);
	}
	new_node = binary_tree_node(parent, value);
	if (!parent)
		*tree = new_node;
	else if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;
	rebalance(tree, new_node);
	return (new_node);
}
