#include "binary_trees.h"

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
