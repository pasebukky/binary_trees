#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 *
 * @node: pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node.
 * If node is NULL, return NULL
 * If node has no uncle, return NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	return (NULL);

binary_tree_t *grandparent = node->parent->parent;

if (grandparent == NULL)
	return (NULL);

if (grandparent->left == node->parent)
	return (grandparent->right);
return (grandparent->left);
}
