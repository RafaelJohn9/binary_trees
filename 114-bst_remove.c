#include "binary_trees.h"

/**
 * search- searches for a value in a binary search tree
 * @tree: node of the tree
 * @value: int value to be searched
 * Return: a pointer to the node found
 */
bst_t *search(const bst_t *tree, int value)
{
	if (!tree)
	{
		return (NULL);
	}

	if (value < tree->n)
	{
		return (search(tree->left, value));
	}
	else if (value > tree->n)
	{
		return (search(tree->right, value));
	}
	else
	{
		return ((bst_t *)tree);
	}
}

/**
 * bst_remove- removes a node from a binary tree
 * @root: ptr to the root node of the tree
 * @value of the node to be removed
 * Return: new root node after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *replacer = NULL, *nodeToBeDeleted = NULL, *node=NULL;

	if (!(nodeToBeDeleted =  search(root, value)))
	{
		return (NULL);
	}
	node = nodeToBeDeleted;
	while (node)
	{
		if (node->right)
		{
			if (node->right->left)
			{
				replacer = node->right->left;
				if (!replacer->right && !replacer->left)
				{
					break;
				}
				else if(replacer->left)
				{
					node = replacer->left;
					continue;
				}
				else if(replacer->right)
				{
					node = replacer->right;
				}
			}
			else if (node->right->right)
			{
				node = node->right;
			}
			else
			{
				replacer = node->right;
			}
		}
		else if (node->left)
		{
			if (!node->parent)
			{
				root = node->left;
			}
			node->left->parent = node->parent;
			binary_tree_delete(node);
			return (root);
		}
		else
		{
			binary_tree_delete(node);
			return (root);
		}
	}
	if (replacer)
	{
		nodeToBeDeleted->parent = replacer->parent;
		if (nodeToBeDeleted->parent->left == nodeToBeDeleted)
		{
			nodeToBeDeleted->parent->left = replacer;
		}
		else if (nodeToBeDeleted->parent->right == nodeToBeDeleted)
		{
			nodeToBeDeleted->parent->right = replacer;
		}

		nodeToBeDeleted->left = replacer->left;
		nodeToBeDeleted->right = replacer->right;
		if (!replacer->parent)
			root = replacer;
	}
	binary_tree_delete(nodeToBeDeleted);
	return (root);
}
