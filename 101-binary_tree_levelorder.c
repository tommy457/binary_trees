#include "binary_trees.h"

void levelorder_recurive(
		const binary_tree_t *tree, size_t level, void (*func)(int));

/**
 * binary_tree_levelorder - goes through a binary tree level-order traversal.
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node.
 *
 * Return: NA.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		size_t height, level;

		height = binary_tree_height(tree) + 1;

		for (level = 1; level <= height; level++)
		{
			levelorder_recurive(tree, level, func);
		}
	}
}


/**
 * levelorder_recurive - recursive finction to print each level of the tree.
 * @tree: pointer to the root node of the tree to traverse.
 * @level: level of the tree
 * @func: pointer to a function to call for each node.
 *
 * Return: NA.
 */

void levelorder_recurive(
		const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);

	else if (level > 1)
	{
		levelorder_recurive(tree->left, level - 1, func);
		levelorder_recurive(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_height - function that measures the height of a binary tree.
 * @tree: pointer to the root node.
 *
 * Return: height of a node or 0..
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left = 0, right = 0;

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
