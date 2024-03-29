#include "binary_trees.h"

/**
 * balance_factor - Measures balance factor of an AVl tree
 * @tree: root of the tree
 * Return: balance factor
 */
void balance_factor(avl_t **tree)
{
	int bfactor;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	balance_factor(&(*tree)->left);
	balance_factor(&(*tree)->right);
	bfactor = binary_tree_balance((const binary_tree_t *)*tree);
	if (bfactor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bfactor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * min - move min node to sub tree
 * @node: root of the tree
 * Return: the min value of this tree
 */
int min(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = min(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 *remove_type - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = min(root->right);
		root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return:  a pointer to the root of the created AVL tree, NULL on failure
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp = (avl_t *) bst_remove((bst_t *) root, value);

	if (temp == NULL)
		return (NULL);
	balance_factor(&temp);
	return (temp);
}
