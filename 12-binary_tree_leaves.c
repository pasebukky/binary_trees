#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 *
 * @tree: pointer to the root node of the tree to count the number of leaves
 *
 * Return: Leaf count. If tree is NULL, your function must return 0
 * A NULL pointer is not a leaf
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
if (tree == NULL)
	return (0);

if (tree->right == NULL && tree->left == NULL)
	return (1);

return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
