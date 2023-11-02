#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 *
 * Return: pointer to the new root node or NULL
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node, *root;
	int left_child = 0;

	if (!tree)
		return (NULL);

	node = tree->right;
	if (node)
	{
		root = tree->parent;
		if (root)
			left_child = tree->parent->left == tree;

		tree->right = node->left;

		if (node->left)
			node->left->parent = tree;

		tree->parent = node;
		node->left = tree;
		node->parent = root;

		if (root)
		{
			if (left_child)
				root->left = node;
			else
				root->right = node;
		}
	}
	while (tree->parent)
		tree = tree->parent;

	return (tree);
}
