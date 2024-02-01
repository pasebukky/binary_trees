#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_height - a function to calculate the height of a binary tree
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
 * binary_tree_is_leaf - checks if a node is a leaf
 *
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, otherwise 0. If node is NULL, return 0
*/

int binary_tree_is_leaf(const binary_tree_t *node)
{
if (node == NULL || node->left != NULL || node->right != NULL)
        return (0);
else
        return (1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (1);
	left = tree->left;
	right = tree->right;
	if (binary_tree_is_leaf(tree))
		return (1);
	if (left == NULL || right == NULL)
		return (0);
	if (binary_tree_height(left) == binary_tree_height(right))
	{
		if (binary_tree_is_perfect(left) && binary_tree_is_perfect(right))
			return (1);
	}
	return (0);
}
/**
 * binary_tree_is_complete - a function that checks if binary tree is complete
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t left_height, right_height;
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	left = tree->left;
	right = tree->right;
	left_height = binary_tree_height(left);
	right_height = binary_tree_height(right);
	if (left_height == right_height)
	{
		if (binary_tree_is_perfect(left) && binary_tree_is_complete(right))
			return (1);
	}
	else if (left_height == right_height + 1)
	{
		if (binary_tree_is_complete(left) && binary_tree_is_perfect(right))
			return (1);
	}
	return (0);
}
