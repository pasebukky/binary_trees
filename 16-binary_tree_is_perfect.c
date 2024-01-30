#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, otherwise 0. If tree is NULL, return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (tree == NULL)
	return (0);

size_t left_height;
size_t right_height;

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

if (binary_tree_is_full(tree) && (left_height == right_height))
	return (1);
else
	return (0);
}


/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: Tree height. If tree is NULL, your function must return 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height;
size_t right_height;

if (tree == NULL)
	return (0);

if (tree->left)
	left_height = 1 + binary_tree_height(tree->left);
else
	left_height = 0;

if (tree->right)
	right_height = 1 + binary_tree_height(tree->right);
else
	right_height = 0;

return (left_height > right_height ? left_height : right_height);
}



/**
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if full, otherwise 0. If tree is NULL, your function must return 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
if (tree == NULL)
	return (0);

if (tree->right == NULL && tree->left == NULL)
	return (1);

if (tree->right == NULL || tree->left == NULL)
	return (0);

if (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right))
	return (1);
else
	return (0);
}
