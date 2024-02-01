#include "binary_trees.h"

/**
 * count_nodes - ounts the number of nodes inside a tree
 * @root: Pointer to tree's root
 *
 * Return: Number of nodes
 */
int count_nodes(binary_tree_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + count_nodes(root->left) +
		    count_nodes(root->right));
}

/**
 * sort - move a node value to a correct position in the heap
 * @parent: pointer to the node of the heap
 */
void sort(heap_t *parent)
{
	int temp;
	heap_t *max_child = NULL;

	if (parent == NULL)
		return;

	while (parent && parent->left)
	{
		max_child = parent->left;

		if (parent->right && parent->right->n > parent->left->n)
			max_child = parent->right;

		if (max_child->n > parent->n)
		{
			temp = parent->n;
			parent->n = max_child->n;
			max_child->n = temp;
		}

		parent = max_child;
	}
}

/**
 * get_parent - search for the parent of a node
 * @root: Pointer to heap's node
 * @i: index of the current node
 * @target_index: searched index
 *
 * Return: Pointer to heap's node
 */
heap_t *get_parent(heap_t *root, int i, int target_index)
{
	heap_t *left = NULL, *right = NULL;

	if (root == NULL || i > target_index)
		return (NULL);

	if (i == target_index)
		return (root);

	left = get_parent(root->left, i * 2 + 1, target_index);
	if (left)
		return (left);

	right = get_parent(root->right, i * 2 + 2, target_index);
	if (right)
		return (right);

	return (NULL);
}

/**
 * rm_last_node - Removes the last node of a heap
 * @root: Doublepointer to heap's root node
 * @parent: Pointer to parent node from which to remove the last node
 */
void rm_last_node(heap_t **root, heap_t *parent)
{
	if (parent == *root && !parent->left)
	{
		free(*root);
		*root = NULL;

		return;
	}

	if (parent->right)
	{
		(*root)->n = parent->right->n;
		free(parent->right);
		parent->right = NULL;
	}
	else if (parent->left)
	{
		(*root)->n = parent->left->n;
		free(parent->left);
		parent->left = NULL;
	}

	sort(*root);
}

/**
 * heap_extract - a function that extracts the max value of a heap
 * @root: Double pointer to heaps root
 *
 * Return: max value of heap
 */
int heap_extract(heap_t **root)
{
	int nodes, target_index = 0, max_val = 0;
	heap_t *parent;

	if (!root || !(*root))
		return (0);

	max_val = (*root)->n;
	nodes = count_nodes(*root);

	target_index = (nodes - 2) / 2;
	parent = get_parent(*root, 0, target_index);

	rm_last_node(root, parent);

	return (max_val);
}
