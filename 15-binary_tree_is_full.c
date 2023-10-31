#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: pointer to the root node node of the tree to check.
 *
 * Return: 1 or 0.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
			(tree->left == NULL && tree->right != NULL) ||
			!binary_tree_is_full(tree->left) ||
			!binary_tree_is_full(tree->right)
		   )
			return (0);
	}
	return (1);
}
