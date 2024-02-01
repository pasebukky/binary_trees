#include "binary_trees.h"

/**
 * is_bst_helper - helper functionto execute logic for is_bst
 * @tree: a pointer to the root of the tree
 * @min: value of the smallest node visited thus far
 * @max: value of the largest node visited this far
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);
		return (is_bst_helper(tree->left, min, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, max));
	}
	return (1);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	/* Error handling: check if tree is null */
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
