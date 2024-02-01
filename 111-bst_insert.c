#include "binary_trees.h"

/**
 * bst_insert - a function that inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST
 * @value: value to store in the node
 *
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp;

	if (tree)
	{
		if (*tree == NULL)
		{
			*tree = (bst_t *)binary_tree_node(NULL, value);
			return (*tree);
		}
		temp = *tree;
		while (temp)
		{
			if (temp->n == value)
				break;
			if (temp->n > value)
			{
				if (!temp->left)
				{
					temp->left = (bst_t *)binary_tree_node(temp, value);
					return (temp->left);
				}
				temp = temp->left;
			}
			else if (temp->n < value)
			{
				if (!temp->right)
				{
					temp->right = (bst_t *)binary_tree_node(temp, value);
					return (temp->right);
				}
				temp = temp->right;
			}
		}
	}
	return (NULL);
}
