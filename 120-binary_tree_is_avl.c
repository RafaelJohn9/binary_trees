#include "binary_trees.h"
#include <limits.h>
#include <math.h>

int inorder(const binary_tree_t *tree, int *prev);
/**
 * binary_tree_is_bst - check if bt is bst
 * @tree: tree
 * Return: 0 or 1
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev;

	if (!tree)
		return (0);
	prev = INT_MIN;
	return (inorder(tree, &prev));
}

/**
 * inorder - helper
 * @tree: tree
 * @prev: prev
 * Return: 0 or 1
 */
int inorder(const binary_tree_t *tree, int *prev)
{
	if (!tree)
		return (1);
	if (!inorder(tree->left, prev))
		return (0);
	if (*prev >= tree->n)
		return (0);
	*prev = tree->n;
	return (inorder(tree->right, prev));
}

/**
 * binary_tree_height - calculate the height of a binary tree
 * @tree: the binary tree
 * Return: number of nodes
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lv, rv, max;

	if (tree == NULL)
		return (0);

	lv = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rv = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	max = lv > rv ? lv : rv;
	return (max);
}

/**
 * binary_tree_balance - check if a binary tree is balanced or not
 * Description: check if all nodes have a left/right nodes
 *
 * @tree: the binary tree
 * Return: 0 not balanced | 1 balanced
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lv, rv;

	if (tree == NULL)
		return (1);

	if (binary_tree_balance(tree->left) == 0
	    || binary_tree_balance(tree->right) == 0)
		return (0);

	lv = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rv = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(lv - rv) > 1)
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl - check if a binary tree is AVL
 * @tree: binary tree
 * Return: 0 (not AVL) | 1 (is AVL)
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int isBST, isBalanced;

	if (tree == NULL)
		return (0);

	isBST = binary_tree_is_bst(tree);
	isBalanced = binary_tree_balance(tree);

	if (isBST && isBalanced)
		return (1);

	return (0);
}
