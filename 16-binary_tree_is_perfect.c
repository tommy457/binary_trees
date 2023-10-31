#include "binary_trees.h"

int binary_tree_is_full_rec(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 or 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree)
	{
		if (binary_tree_is_full(tree) &&
				binary_tree_height(tree->left) == binary_tree_height(tree->right)
		   )
		{
			return (1);
		}
	}
	return (0);
}

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: pointer to the root node node of the tree to check.
 *
 * Return: 1 or 0.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_is_full_rec(tree));
	return (0);
}

/**
 * binary_tree_is_full_rec - a recursive helper function.
 * @tree: pointer to the root node node of the tree to check.
 *
 * Return: 1 or 0.
 */

int binary_tree_is_full_rec(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
				(tree->left == NULL && tree->right != NULL) ||
				!binary_tree_is_full_rec(tree->left) ||
				!binary_tree_is_full_rec(tree->right)
		   )
			return (0);
	}
	return (1);
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
