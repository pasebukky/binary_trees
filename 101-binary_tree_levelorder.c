#include "binary_trees.h"

/**
 * binary_tree_height - a function to measure the height of a binary tree
 * @tree: pointer to the root of the tree
 *
 * Return: 0 if tree is NULL, otherwise return height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t L, R;

	if (tree == NULL)
		return (0);
	L = binary_tree_height(tree->left);
	R = binary_tree_height(tree->right);
	if (L >= R)
		return (1 + L);
	return (1 + R);
}

/**
 * binary_tree_level_func - execute function pointer on a single level
 * @tree: the root of the tree
 * @level: level of the tree to perform function on
 * @func: function to perform
 */
void binary_tree_level_func(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		binary_tree_level_func(tree->left, level - 1, func);
		binary_tree_level_func(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - a function that goes through a binary tree
 * using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (i = 1; i <= height; i++)
		binary_tree_level_func(tree, i, func);
}
