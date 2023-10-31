#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: pointer to the root node.
 *
 * Return: balance factor of a binary tree or 0.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
	return (0);
}

/**
 * binary_tree_height - function that measures the height of a binary tree.
 * @tree: pointer to the root node.
 *
 * Return: depth of a node or 0..
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left = 1, right = 1;

		if (!binary_tree_is_leaf(tree))
		{
			left = binary_tree_height(tree->left) + 1;
			right = binary_tree_height(tree->right) + 1;
		}
		return (left > right ? left : right);
	}
	return (0);
}

/**
 * binary_tree_is_leaf - function that checks if a node is a leaf.
 * @node: pointer to the node to check.
 *
 * Return: 1 or 0.
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->left || node->right)
		return (0);

	return (1);
}
