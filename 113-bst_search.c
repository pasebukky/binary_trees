#include "binary_trees.h"

/**
 * bst_search - a function that searches for a value in a binary search tree
 * @tree: pointer to the root node of the BST
 * @value: value to search in the tree
 *
 * Return: pointer to the node containing a value equal to value, or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *temp;

	temp = (bst_t *)tree;
	while (temp)
	{
		if (temp->n == value)
			return (temp);
		if (temp->n < value)
			temp = temp->right;
		else
			temp = temp->left;
	}
	return (NULL);
}
