#include "binary_trees.h"

/**
 * array_to_bst- builds a binary search tree from an array
 * @array: array to be searched
 * @size: size of the array
 * Return: a ptr to the array head
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root;

	if (size == 0)
	{
		return (NULL);
	}
	while (i < size)
	{
		bst_insert(&root, array[i]);
		i++;
	}
	if(!root)
	{
		return (NULL);
	}
	return (root);
}
