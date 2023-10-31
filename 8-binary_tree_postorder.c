#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through binary tree with post-order traversal.
 * @tree: pointer to the root node of the tree to delete.
 * @func: pointer to a function to call for each node.
 *
 * Return: NA.
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
