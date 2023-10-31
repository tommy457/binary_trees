#include "binary_trees.h"

int binary_tree_is_full_rec(const binary_tree_t *tree);

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
