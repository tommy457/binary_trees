#include "binary_trees.h"

int binary_tree_is_complete_rec(
		const binary_tree_t *tree, size_t index, size_t size);

/**
 * binary_tree_is_complete - function that checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 or 0.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size, index = 0;

	if (tree)
	{
		size = binary_tree_size(tree);
		return (binary_tree_is_complete_rec(tree, index, size));
	}
	return (0);
}

/**
 * binary_tree_is_complete_rec - checks if a binary tree is complete recursivly
 * @tree: pointer to the root node of the tree to check.
 * @index: index of a node.
 * @size: number of nodes in a binary tree.
 *
 * Return: 1 or 0.
 */

int binary_tree_is_complete_rec(
		const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (
			binary_tree_is_complete_rec(tree->left, 2 * index + 1, size) &&
			binary_tree_is_complete_rec(tree->right, 2 * index + 2, size)
	       );
}

/**
 * binary_tree_size - function that measures the size of a binary tree.
 * @tree: pointer to the root node.
 *
 * Return: size of a node or 0.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
		size += 1;
	}
	return (size);
}
