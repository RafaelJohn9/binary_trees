#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @node_a: Pointer to the first node.
 * @node_b: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *node_a,
		const binary_tree_t *node_b)
{
	binary_tree_t *parent_a, *parent_b;

	if (!node_a || !node_b)
		return (NULL);

	if (node_a == node_b)
		return ((binary_tree_t *)node_a);

	parent_a = node_a->parent;
	parent_b = node_b->parent;

	if (!parent_a || node_a == parent_b || (!parent_a->parent && parent_b))
		return (binary_trees_ancestor(node_a, parent_b));
	else if (!parent_b || parent_a == node_b || (!parent_b->parent && parent_a))
		return (binary_trees_ancestor(parent_a, node_b));

	return (binary_trees_ancestor(parent_a, parent_b));
}
