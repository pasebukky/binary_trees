#include "binary_trees.h"

/**
 * is_avl_helper - helper that executes the logic of is_avl
 * @tree: pointer to the root node of the tree
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 if tree is avl
 *         0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int path_l, path_r;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	path_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(path_l - path_r) > 1)
		return (0);

	return (is_avl_helper(tree->left, min, tree->n - 1) &&
		is_avl_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_left > height_right ? height_left : height_right);
}

/*
 * binary_tree_is_avl - check if a tree is an Adelson-Velsky and Landis tree
 * @tree: pointer to the root
 *
 * Return: 1 if tree is avl
 *         else return 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
        if (!tree)
                return (0);

        return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
