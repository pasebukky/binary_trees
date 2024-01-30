#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, your function must return NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
if (first == NULL || second == NULL)
	return (NULL);

size_t first_height;
size_t second_height;

first_height = binary_tree_height(first);
second_height = binary_tree_height(second);

while (first_height > second_height)
{
	first = first->parent;
	first_height--;
}

while (second_height > first_height)
{
	second = second->parent;
	second_height--;
}

while (first != second && first != NULL && second != NULL)
{
	first = first->parent;
	second = second->parent;
}
return ((binary_tree_t *)first);
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
if (tree == NULL)
	return (0);

size_t left_height;
size_t right_height;

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

if (left_height > right_height)
	return (left_height + 1);
else
	return (right_height + 1);
}
