#include "binary_trees.h"

/**
 * array_to_bst - function that builds a Binary Search Tree from an array.
 * @array: pointer to the first element of the array to be converted.
 * @size: number of element in the array.
 *
 * Return: return a pointer to the root node of the created BST or NULL.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root = NULL;

	if (array)
	{
		while (i < size)
		{
			bst_insert(&root, array[i]);
			i++;
		}
	}
	return (root);
}
