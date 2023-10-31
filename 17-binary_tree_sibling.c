#include "binary_trees.h"

/**
 * binary_tree_sibling - function that finds the sibling of a node.
 * @node: pointer to the node to find the sibling.
 *
 * Return: pointer to the sibling node or NULL.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node && node->parent)
	{
		return (
			node->parent->right == node ?
			node->parent->left : node->parent->right);
	}
	return (NULL);
}
