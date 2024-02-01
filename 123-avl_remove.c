#include "binary_trees.h"

/**
 * min - gets the min node
 * @node: root node
 *
 * Return: node with the min value
 */
static bst_t *min(bst_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->left == NULL)
		return (node);
	return (min(node->left));
}

/**
 * rm_node - removes a value from a binary search tree
 * @root: root of the tree
 * @value: value of node to remove
 *
 * Return: the parent
 */
static bst_t *rm_node(bst_t **root, int value)
{
	bst_t *node = *root, *parent = NULL, **plink, *new, *source = NULL;

	while (node)
	{
		if (node->n == value)
		{
			parent = node->parent, source = parent;
			plink = parent == NULL ? root : parent->n > node->n ? &parent->left
			: &parent->right;
			if (node->right == NULL && node->left == NULL)
				*plink = NULL;
			else if (node->right == NULL)
				*plink = node->left, node->left->parent = node->parent;
			else if (node->left == NULL)
				*plink = node->right, node->right->parent = node->parent;
			else
			{
				new = min(node->right);
				if (new == node->right)
					*plink = new, new->parent = node->parent, source = node->parent,
					new->left = node->left, new->left->parent = new;
				else
				{
					new->parent->left = new->right, source = new->parent;
					if (new->right)
						new->right->parent = new->parent;
					*plink = new, new->parent = parent, new->left = node->left;
					if (new->left)
						new->left->parent = new;
					new->right = node->right;
					if (new->right)
						new->right->parent = new;
				}
			}
			free(node);
			break;
		}
		node = value > node->n ? node->right : node->left;
	}
	return (source);
}

/**
 * balance_tree - Adjusts the balance of an AVL tree by \
 * rotating the unbalanced subtree.
 * @root: A pointer to the address of the root of the tree.
 * @node: A pointer to the inserted node.
 */
void balance_tree(avl_t **root, avl_t *node)
{
	avl_t *current = node, *new_root = *root;
	int balance = 0;

	while (current != NULL)
	{
		balance = binary_tree_balance(current);
		if (!((balance >= -1) && (balance <= 1)))
		{
			if ((balance == 2) && ((binary_tree_balance(current->left) == 1)
				|| (binary_tree_balance(current->left) == 0)))
			{
				new_root = binary_tree_rotate_right(current);
			}
			else if ((balance == 2) && (binary_tree_balance(current->left) == -1))
			{
				current->left = binary_tree_rotate_left(current->left);
				new_root = binary_tree_rotate_right(current);
			}
			else if ((balance == -2) && ((binary_tree_balance(current->right) == -1)
				|| (binary_tree_balance(current->right) == 0)))
			{
				new_root = binary_tree_rotate_left(current);
			}
			else if ((balance == 2) && (binary_tree_balance(current->left) == -1))
			{
				current->right = binary_tree_rotate_right(current->right);
				new_root = binary_tree_rotate_left(current);
			}
			new_root = (current == *root ? new_root : *root);
			break;
		}
		current = current->parent;
	}
	*root = new_root;
}

/**
 * avl_remove - rm a node with a given value from an AVL tree
 * @root: root of the tree
 * @value: The value of the node to remove
 *
 * Return: The new root,
 * NULL on failure
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node = NULL, *new_root = root, *new_node = NULL, *parent = NULL;

	if (new_root != NULL)
	{
		(void)node;
		(void)new_node;
		parent = rm_node(&new_root, value);
		balance_tree(&new_root, parent);
	}
	return (new_root);
}
