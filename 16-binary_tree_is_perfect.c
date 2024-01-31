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
size_t height = 0;
size_t power = 0;
size_t nodes = 0;

if (tree == NULL)
	return (0);

if ((tree->right == NULL) && (tree->left == NULL))
	return (1);

height = binary_tree_height(tree);
power = (size_t)square_value(2, height + 1);
nodes = binary_tree_size(tree);

return (power - 1 == nodes);
}



/**
 * square_value - calculates the square value of x raised to the power of y
 *
 * @x: the base
 * @y: the exponent
 *
 * Return: the square value or -1 if y is negative
 */

int square_value(int x, int y)
{
if (y < 0)
	return (-1);
else if (y == 0)
	return (1);
else
	return (x * square_value(x, y - 1));
}



/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: Tree size. If tree is NULL, your function must return 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
if (tree == NULL)
	return (0);
else
	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
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
