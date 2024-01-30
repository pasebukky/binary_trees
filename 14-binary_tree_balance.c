#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balancing factor. If tree is NULL, your function must return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
size_t left_height;
size_t right_height;

if (tree == NULL)
	return (0);

if (tree->left != NULL)
	left_height = (int)binary_tree_height(tree->left);
else
	left_height = -1;

if (tree->right != NULL)
	right_height = (int)binary_tree_height(tree->right);
else
	right_height = -1;

return ((int)(left_height - right_height));
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
