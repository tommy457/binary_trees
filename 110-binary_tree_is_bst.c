#include "binary_trees.h"

int binary_tree_is_bst_rec(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 or 0;
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_is_bst_rec(tree, INT_MIN, INT_MAX));

	return (0);
}

/**
 * binary_tree_is_bst_rec - checks if a binary tree is a valid BST recursivly.
 * @tree: pointer to the root node of the tree to check.
 * @min: minimum value of Binary Search Tree.
 * @max: maximum value of Binary Search Tree.
 *
 * Return: 1 or 0.
 */

int binary_tree_is_bst_rec(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n > max || tree->n < min)
		return (0);

	return (binary_tree_is_bst_rec(tree->left, min, tree->n - 1) &&
			binary_tree_is_bst_rec(tree->right, tree->n + 1, max));
}
