#include "binary_trees.h"

/**
 * count_nodes - function that returns the number of nodes in a tree
 * @root: root of tree
 *
 * Return: number of nodes
 */
int count_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_nodes(root->left) +
		    count_nodes(root->right));
}

/**
 * heap_to_sorted_array - a function that converts a Binary Max Heap
 * to a sorted array
 * @heap: Pointer to heap's node
 * @size: Pointer to arrays size
 *
 * Return: array of ints
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, nodes, *arr = NULL;

	*size = 0;
	if (heap == NULL)
		return (NULL);

	nodes = count_nodes(heap);
	arr = malloc(sizeof(*arr) * nodes);
	if (!arr)
		return (NULL);

	*size = nodes;
	for (i = 0; i < nodes; i++)
		arr[i] = heap_extract(&heap);

	return (arr);
}
