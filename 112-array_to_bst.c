#include "binary_trees.h"

/**
 * array_to_bst - a function that builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 *
 *
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;
	
	/* loop through array */
	for (i = 0; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}
	return (root);
}
