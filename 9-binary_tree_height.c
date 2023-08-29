#include "binary_trees.h"

/**
 * binary_tree_height- a function that measures the height of a binary tree
 * @tree: a ptr to the root node of the tree to measure the height
 * Return: size of the tree from current position
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_result = 0, right_result = 0;
	size_t result = 0;

	if (!tree)
	{
		return (0);
	}

	if (!(tree->left) && !(tree->right))
	{
		return (0);
	}
	if tree->left
	{
		 left_result += binary_tree_height(tree->left);
		 left_result++;
	}
	if tree->right
	{
		 right_result += binary_tree_height(tree->right);
		 right_result++;
	}
	if (left_result > right_result)
	{
		result += left_result;
	}
	else
	{
		result += right_result;
	}
	return (result);
}
