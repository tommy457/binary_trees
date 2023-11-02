#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 *
 * Return: pointer to the new root node or NULL
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node, *root;
	int root_leftchild = 0;

	if (!tree)
		return (NULL);

	node = tree->left;
	if (node)
	{
		root = tree->parent;
		if (root)
			root_leftchild = tree->parent->left == tree;

		tree->left = node->right;
		if (node->right)
			node->right->parent = tree;

		tree->parent = node;
		node->right = tree;
		node->parent = root;

		if (root)
		{
			if (root_leftchild)
				root->left = node;
			else
				root->right = node;
		}
	}
	while (tree->parent)
		tree = tree->parent;

	return (tree);
}
