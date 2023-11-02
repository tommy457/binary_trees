#include "binary_trees.h"

bst_t *swap_nodes(bst_t *first_node, bst_t *second_node);
/**
 * bst_remove- function that removes a node from a Binary Search Tree.
 * @root: pointer to the root node of the tree where you will remove a node.
 * @value: value to remove in the tree.
 *
 * Return: pointer to the root node after removing or NULL.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *first_node, *node;
	int left_child = 0;

	if (root)
	{
		first_node = bst_search(root, value);
		if (!first_node)
			return (NULL);

		if (first_node->parent)
			left_child = first_node->parent->left == first_node;

		if (!first_node->right && !first_node->left)
		{
			if (!first_node->parent)
			{
				free(first_node);
				return (NULL);
			}
			if (left_child)
				first_node->parent->left = NULL;
			else
				first_node->parent->right = NULL;
			node = first_node->parent;

			while (node->parent)
				node = node->parent;
			free(first_node);

			return (node);
		}
		if (!first_node->right)
			return (swap_nodes(first_node, first_node->left));
		node = first_node->right;

		while (node->left)
			node = node->left;

		return (swap_nodes(first_node, node));
	}
	return (NULL);
}

/**
 * bst_search - function that searches for a value in a Binary Search Tree.
 * @tree: pointer to the first element of the array to be converted.
 * @value: the value to search in the tree.
 *
 * Return: pointer to the node containing a value equals to value or NULL.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree)
	{
		while (tree)
		{
			if (value == tree->n)
				return ((bst_t *)tree);
			tree = (tree->n > value) ? tree->left : tree->right;
		}
		return ((bst_t *)tree);
	}
	return (NULL);
}

/**
 * swap_nodes - function that swaps two nodes in a Binary Search Tree.
 * @first_node: first node.
 * @second_node: second node.
 *
 * Return: pointer to root node.
 */

bst_t *swap_nodes(bst_t *first_node, bst_t *second_node)
{
	bst_t *node = NULL;
	int left_child = 0;

	if (first_node->parent)
		left_child = first_node->parent->left == first_node;

	if (second_node->parent && second_node->parent != first_node)
		second_node->parent->left = NULL;

	second_node->parent = first_node->parent;
	if (first_node->parent)
	{
		if (left_child)
			first_node->parent->left = second_node;
		else
			first_node->parent->right = second_node;
	}
	if (first_node->left != second_node)
	{
		second_node->left = first_node->left;
		first_node->left->parent = second_node;
	}
	if (first_node->right && first_node->right != second_node)
	{
		second_node->right = first_node->right;
		first_node->right->parent = second_node;
	}
	node = second_node;

	while (node->parent)
		node = node->parent;
	free(first_node);

	return (node);
}
