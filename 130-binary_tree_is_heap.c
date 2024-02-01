#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - check max value in tree
 * @tree: pointer to the root
 * Return: 1 if all nodes are max, 0 in other cases
 **/
int check_max(const binary_tree_t *tree)
{
	int temp1 = 1, temp2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		temp1 = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		temp2 = check_max(tree->right);
	}
	return (temp1 && temp2);
}
/**
 * binary_tree_is_heap - function that checks if tree is valid Max Binary Heap
 * @tree: root of tree
 * Return: return 1 if tree is a valid Max Binary Heap, and 0 otherwise
 * If tree is NULL, return 0
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int temp;

	if (!tree)
		return (0);

	temp = binary_tree_is_complete(tree);
	if (!temp)
		return (0);
	return (check_max(tree));
}
