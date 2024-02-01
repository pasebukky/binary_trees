#include "binary_trees.h"

/**
 * arr_to_avl_helper - helper that builds an AVL tree from an array
 * @root: double pointer to the root node of the subtree
 * @array: a pointer to the first element of the array to be converted
 * @min: lower bound index
 * @max: upper bound index
 */
void arr_to_avl_helper(avl_t **root, int *array, size_t min, size_t max)
{
        avl_t *new_t = NULL;
        size_t middle;

        if (max - min > 1)
        {
                middle = (max - min) / 2 + min;
                new_t = binary_tree_node(*root, array[middle]);
                if (array[middle] > (*root)->n)
                        (*root)->right = new_t;
                else if (array[middle] < (*root)->n)
                        (*root)->left = new_t;
                arr_to_avl_helper(&new_t, array, min, middle);
                arr_to_avl_helper(&new_t, array, middle, max);
        }
}

/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: a pointer to the root node of the created AVL tree
 *         NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *avl_tree = NULL;
	size_t middle;

	if (!array)
		return (NULL);
	middle = (size - 1) / 2;
	avl_tree = binary_tree_node(NULL, array[middle]);

	arr_to_avl_helper(&avl_tree, array, -1, middle);
	arr_to_avl_helper(&avl_tree, array, middle, size);

	return (avl_tree);
}
