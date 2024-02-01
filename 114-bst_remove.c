include "binary_trees.h"

/**
 * search - a functin that searches for a node in a binary tree
 * @root: the root of the binary tree
 * @value: the value of the node
 * Return: a pointer to  the node if found, otherwise null
 */
bst_t *search(bst_t *root, int value)
{
	bst_t *node = NULL;

	if (root != NULL)
	{
		if (root->left != NULL)
			node = root->left->parent;
		if ((node == NULL) && (root->right != NULL))
			node = root->right->parent;
		while (node != NULL)
		{
			if (node->n < value)
				node = node->right;
			else if (node->n > value)
				node = node->left;
			else
				break;
		}
	}
	return (node);
}

/**
 * replace_with_successor - Replaces a node with its inorder \
 * successor in a binary search tree.
 * @node: A pointer to the node in the BST
 *
 * Return: A pointer to the node's inorder successor node.
 */
bst_t *replace_with_successor(bst_t **node)
{
	bst_t *temp;

	temp = (*node)->right;
	while ((temp != NULL) && (temp->left != NULL))
		temp = temp->left;
	if ((temp != NULL) && (temp == (*node)->right))
	{
		temp->parent = (*node)->parent;
		temp->left = (*node)->left;
		if ((*node)->left != NULL)
			(*node)->left->parent = temp;
		if ((*node)->parent != NULL)
		{
			if ((*node)->parent->left == *node)
				(*node)->parent->left = temp;
			if ((*node)->parent->right == *node)
				(*node)->parent->right = temp;
		}
	}
	else if (temp != NULL)
	{
		temp->parent->left = temp->right;
		if (temp->right != NULL)
			temp->right->parent = temp->parent;
		temp->parent = (*node)->parent;
		temp->left = (*node)->left;
		temp->right = (*node)->right;
		(*node)->left->parent = temp;
		(*node)->right->parent = temp;
		if ((*node)->parent != NULL)
		{
			if ((*node)->parent->left == *node)
				(*node)->parent->left = temp;
			if ((*node)->parent->right == *node)
				(*node)->parent->right = temp;
		}
	}
	return (temp);
}

/**
 * bst_remove - Removes a node with a given value in a binary search tree.
 * @root: The binary search tree.
 * @value: The value of the node.
 *
 * Return: A pointer to the tree's root node, otherwise NULL.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL, *new_root = root, *temp = NULL;

	if (new_root != NULL)
	{
		node = search(root, value);
		if ((node != NULL) && (node->n == value))
		{
			if ((node->left == NULL) && (node->right == NULL))
			{
				if (node->parent != NULL)
				{
					if (node->parent->left == node)
						node->parent->left = NULL;
					if (node->parent->right == node)
						node->parent->right = NULL;
				}
			}
			else if ((node->left != NULL) ^ (node->right != NULL))
			{
				temp = (node->left != NULL ? node->left : node->right);
				if (node->parent != NULL)
				{
					if (node->parent->left == node)
						node->parent->left = temp;
					else if (node->parent->right == node)
						node->parent->right = temp;
				}
				temp->parent = node->parent;
			}
			else
			{
				temp = replace_with_successor(&node);
			}
			new_root = (node->parent == NULL ? temp : root);
			free(node);
		}
	}
	return (new_root);
}
