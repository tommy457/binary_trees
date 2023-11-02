#include "binary_trees.h"

/**
 * bst_search - array_to_bst - searches for a value in a Binary Search Tree.
 * @tree: pointer to the first element of the array to be converted.
 * @value: the value to search in the tree.
 *
 * Return: pointer to the node containing a value equals to value or NULL
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
