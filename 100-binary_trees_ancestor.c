#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 *
 * Return: pointer to the lowest common ancestor or NULL.
 */

binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second)
{
	size_t right_depth, left_depth;
	binary_tree_t *first_cpy, *second_cpy;

	if (!first || !second)
		return (NULL);

	first_cpy = (binary_tree_t *)first;
	second_cpy = (binary_tree_t *)second;
	right_depth = binary_tree_depth(first_cpy);
	left_depth = binary_tree_depth(second_cpy);

	if (right_depth > left_depth)
	{
		while (right_depth > left_depth)
		{
			first_cpy = first_cpy->parent;
			right_depth--;
		}
	}
	else
	{
		while (left_depth > right_depth)
		{
			second_cpy = second_cpy->parent;
			left_depth--;
		}
	}
	while (first_cpy && second_cpy)
	{
		if (first_cpy == second_cpy)
			return (first_cpy);

		first_cpy = first_cpy->parent;
		second_cpy = second_cpy->parent;
	}
	return (NULL);
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: pointer to the root node.
 *
 * Return: depth of a node or 0.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
	{
		size_t depth = 0;

		depth = binary_tree_depth(tree->parent) + 1;
		return (depth);
	}
	return (0);
}
