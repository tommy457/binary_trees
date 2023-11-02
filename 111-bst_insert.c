#include "binary_trees.h"

/**
 * bst_insert - function that inserts a value in a Binary Search Tree.
 * @tree: double pointer to the root curr of the BST to insert the value.
 * @value: value to store in the curr to be inserted.
 *
 * Return: return a pointer to the created curr or NULL.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node = NULL, *curr;

	if (!tree)
		return (NULL);
	node = calloc(1, sizeof(bst_t));
	if (!node)
		return (NULL);
	node->n = value;
	if (!*tree)
	{
		*tree = node;
		return (node);
	}
	curr = *tree;
	while (1)
	{
		if (curr->n == value)
		{
			free(node);
			return (NULL);
		}
		if (curr->n > value)
		{
			if (!curr->left)
			{
				node->parent = curr;
				return (curr->left = node);
			}
			curr = curr->left;
		}
		else
		{
			if (!curr->right)
			{
				node->parent = curr;
				return (curr->right = node);
			}
			curr = curr->right;
		}
	}
}
