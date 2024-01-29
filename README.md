This repository contains all the solutions to the ALX 0x1D. C - Binary trees task. 


### AUTHORS ###
Nurudeen Ahmed<https://x.com/0xNuru>
Bukky Pase <https://github.com/pasebukky>



All the tasks are detailed below as follows:



## 0-binary_tree_node.c ##
Write a function that creates a binary tree node

Prototype: binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
Where parent is a pointer to the parent node of the node to create
And value is the value to put in the new node
When created, a node does not have any child
Your function must return a pointer to the new node, or NULL on failure




## 1-binary_tree_insert_left.c ##
Write a function that inserts a node as the left-child of another node

Prototype: binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
Where parent is a pointer to the node to insert the left-child in
And value is the value to store in the new node
Your function must return a pointer to the created node, or NULL on failure or if parent is NULL
If parent already has a left-child, the new node must take its place, and the old left-child must be set as the left-child of the new node.





## 2-binary_tree_insert_right.c ##
Write a function that inserts a node as the right-child of another node

Prototype: binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
Where parent is a pointer to the node to insert the right-child in
And value is the value to store in the new node
Your function must return a pointer to the created node, or NULL on failure or if parent is NULL
If parent already has a right-child, the new node must take its place, and the old right-child must be set as the right-child of the new node.




## 3-binary_tree_delete.c ##
Write a function that deletes an entire binary tree

Prototype: void binary_tree_delete(binary_tree_t *tree);
Where tree is a pointer to the root node of the tree to delete
If tree is NULL, do nothing




## 4-binary_tree_is_leaf.c ##
Write a function that checks if a node is a leaf

Prototype: int binary_tree_is_leaf(const binary_tree_t *node);
Where node is a pointer to the node to check
Your function must return 1 if node is a leaf, otherwise 0
If node is NULL, return 0




## 5-binary_tree_is_root.c ##
Write a function that checks if a given node is a root

Prototype: int binary_tree_is_root(const binary_tree_t *node);
Where node is a pointer to the node to check
Your function must return 1 if node is a root, otherwise 0
If node is NULL, return 0



## 6-binary_tree_preorder.c ##
Write a function that goes through a binary tree using pre-order traversal

Prototype: void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
Where tree is a pointer to the root node of the tree to traverse
And func is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
If tree or func is NULL, do nothing





## 7-binary_tree_inorder.c ##
Write a function that goes through a binary tree using in-order traversal

Prototype: void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
Where tree is a pointer to the root node of the tree to traverse
And func is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
If tree or func is NULL, do nothing




## 8-binary_tree_postorder.c ##
Write a function that goes through a binary tree using post-order traversal

Prototype: void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
Where tree is a pointer to the root node of the tree to traverse
And func is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
If tree or func is NULL, do nothing




## 9-binary_tree_height.c ##
Write a function that measures the height of a binary tree

Prototype: size_t binary_tree_height(const binary_tree_t *tree);
Where tree is a pointer to the root node of the tree to measure the height.
If tree is NULL, your function must return 0




## 10-binary_tree_depth.c ##
Write a function that measures the depth of a node in a binary tree

Prototype: size_t binary_tree_depth(const binary_tree_t *tree);
Where tree is a pointer to the node to measure the depth
If tree is NULL, your function must return 0





## 11-binary_tree_size.c ##
Write a function that measures the size of a binary tree

Prototype: size_t binary_tree_size(const binary_tree_t *tree);
Where tree is a pointer to the root node of the tree to measure the size
If tree is NULL, the function must return 0




## 12-binary_tree_leaves.c ##
Write a function that counts the leaves in a binary tree

Prototype: size_t binary_tree_leaves(const binary_tree_t *tree);
Where tree is a pointer to the root node of the tree to count the number of leaves
If tree is NULL, the function must return 0
A NULL pointer is not a leaf




## 13-binary_tree_nodes.c ##
Write a function that counts the nodes with at least 1 child in a binary tree

Prototype: size_t binary_tree_nodes(const binary_tree_t *tree);
Where tree is a pointer to the root node of the tree to count the number of nodes
If tree is NULL, the function must return 0
A NULL pointer is not a node




## 14-binary_tree_balance.c ##
Write a function that measures the balance factor of a binary tree

Prototype: int binary_tree_balance(const binary_tree_t *tree);
Where tree is a pointer to the root node of the tree to measure the balance factor
If tree is NULL, return 0




## 15-binary_tree_is_full.c ##
Write a function that checks if a binary tree is full

Prototype: int binary_tree_is_full(const binary_tree_t *tree);
Where tree is a pointer to the root node of the tree to check
If tree is NULL, your function must return 0



## 16-binary_tree_is_perfect.c ##
Write a function that checks if a binary tree is perfect

Prototype: int binary_tree_is_perfect(const binary_tree_t *tree);
Where tree is a pointer to the root node of the tree to check
If tree is NULL, your function must return 0



## 17-binary_tree_sibling.c ##
Write a function that finds the sibling of a node

Prototype: binary_tree_t *binary_tree_sibling(binary_tree_t *node);
Where node is a pointer to the node to find the sibling
Your function must return a pointer to the sibling node
If node is NULL or the parent is NULL, return NULL
If node has no sibling, return NULL




## 18-binary_tree_uncle.c ##
Write a function that finds the uncle of a node

Prototype: binary_tree_t *binary_tree_uncle(binary_tree_t *node);
Where node is a pointer to the node to find the uncle
Your function must return a pointer to the uncle node
If node is NULL, return NULL
If node has no uncle, return NULL




## 100-binary_trees_ancestor.c ##
Write a function that finds the lowest common ancestor of two nodes

Prototype: binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);
Where first is a pointer to the first node
And second is a pointer to the second node
Your function must return a pointer to the lowest common ancestor node of the two given nodes
If no common ancestor was found, your function must return NULL



## 101-binary_tree_levelorder.c ##
Write a function that goes through a binary tree using level-order traversal

Prototype: void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
Where tree is a pointer to the root node of the tree to traverse
And func is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
If tree or func is NULL, do nothing




## 102-binary_tree_is_complete.c ##
Write a function that checks if a binary tree is complete

Prototype: int binary_tree_is_complete(const binary_tree_t *tree);
Where tree is a pointer to the root node of the tree to check
If tree is NULL, your function must return 0




## 103-binary_tree_rotate_left.c ##
Write a function that performs a left-rotation on a binary tree

Prototype: binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
Where tree is a pointer to the root node of the tree to rotate
Your function must return a pointer to the new root node of the tree once rotated



## 104-binary_tree_rotate_right.c ##
Write a function that performs a right-rotation on a binary tree

Prototype: binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
Where tree is a pointer to the root node of the tree to rotate
Your function must return a pointer to the new root node of the tree once rotated



## 110-binary_tree_is_bst.c ##
Write a function that checks if a binary tree is a valid Binary Search Tree

Prototype: int binary_tree_is_bst(const binary_tree_t *tree);
Where tree is a pointer to the root node of the tree to check
Your function must return 1 if tree is a valid BST, and 0 otherwise
If tree is NULL, return 0
Properties of a Binary Search Tree:

The left subtree of a node contains only nodes with values less than the node’s value
The right subtree of a node contains only nodes with values greater than the node’s value
The left and right subtree each must also be a binary search tree
There must be no duplicate values




## 111-bst_insert.c, 0-binary_tree_node.c ##
Write a function that inserts a value in a Binary Search Tree

Prototype: bst_t *bst_insert(bst_t **tree, int value);
Where tree is a double pointer to the root node of the BST to insert the value
And value is the value to store in the node to be inserted
Your function must return a pointer to the created node, or NULL on failure
If the address stored in tree is NULL, the created node must become the root node.
If the value is already present in the tree, it must be ignored
Your file 0-binary_tree_node.c will be compile during the correction




## 112-array_to_bst.c, 111-bst_insert.c, 0-binary_tree_node.c ##
Write a function that builds a Binary Search Tree from an array

Prototype: bst_t *array_to_bst(int *array, size_t size);
Where array is a pointer to the first element of the array to be converted
And size is the number of element in the array
Your function must return a pointer to the root node of the created BST, or NULL on failure
If a value of the array is already present in the tree, this value must be ignored
Your files 111-bst_insert.c and 0-binary_tree_node.c will be compiled during the correction




## 113-bst_search.c ##
Write a function that searches for a value in a Binary Search Tree

Prototype: bst_t *bst_search(const bst_t *tree, int value);
Where tree is a pointer to the root node of the BST to search
And value is the value to search in the tree
Your function must return a pointer to the node containing a value equals to value
If tree is NULL or if nothing is found, your function must return NULL




## 114-bst_remove.c ##
Write a function that removes a node from a Binary Search Tree

Prototype: bst_t *bst_remove(bst_t *root, int value);
Where root is a pointer to the root node of the tree where you will remove a node
And value is the value to remove in the tree
Once located, the node containing a value equals to value must be removed and freed
If the node to be deleted has two children, it must be replaced with its first in-order successor (not predecessor)
Your function must return a pointer to the new root node of the tree after removing the desired value




## 115-O ##
What are the average time complexities of those operations on a Binary Search Tree (one answer per line):

Inserting the value n
Removing the node with the value n
Searching for a node in a BST of size n




## 120-binary_tree_is_avl.c ##
Write a function that checks if a binary tree is a valid AVL Tree

Prototype: int binary_tree_is_avl(const binary_tree_t *tree);
Where tree is a pointer to the root node of the tree to check
Your function must return 1 if tree is a valid AVL Tree, and 0 otherwise
If tree is NULL, return 0
Properties of an AVL Tree:

An AVL Tree is a BST
The difference between heights of left and right subtrees cannot be more than one
The left and right subtrees must also be AVL trees




## 121-avl_insert.c, 14-binary_tree_balance.c, 103-binary_tree_rotate_left.c, 104-binary_tree_rotate_right.c, 0-binary_tree_node.c ##
Write a function that inserts a value in an AVL Tree

Prototype: avl_t *avl_insert(avl_t **tree, int value);
Where tree is a double pointer to the root node of the AVL tree for inserting the value
And value is the value to store in the node to be inserted
Your function must return a pointer to the created node, or NULL on failure
If the address stored in tree is NULL, the created node must become the root node.
The resulting tree after insertion, must be a balanced AVL Tree
Your files 14-binary_tree_balance.c, 103-binary_tree_rotate_left.c, 104-binary_tree_rotate_right.c and 0-binary_tree_node.c will be compiled during the correction




## 122-array_to_avl.c, 121-avl_insert.c, 0-binary_tree_node.c, 103-binary_tree_rotate_left.c, 104-binary_tree_rotate_right.c, 14-binary_tree_balance.c ##
Write a function that builds an AVL tree from an array

Prototype: avl_t *array_to_avl(int *array, size_t size);
Where array is a pointer to the first element of the array to be converted
And size is the number of element in the array
Your function must return a pointer to the root node of the created AVL tree, or NULL on failure
If a value of the array is already present in the tree, this value must be ignored
Your files 121-avl_insert.c, 0-binary_tree_node.c, 14-binary_tree_balance.c, 103-binary_tree_rotate_left.c and 104-binary_tree_rotate_right.c will be compiled during the correction




## 123-avl_remove.c, 14-binary_tree_balance.c, 103-binary_tree_rotate_left.c, 104-binary_tree_rotate_right.c ##
Write a function that removes a node from an AVL tree

Prototype: avl_t *avl_remove(avl_t *root, int value);
Where root is a pointer to the root node of the tree for removing a node
And value is the value to remove in the tree
Once located, the node containing a value equals to value must be removed and freed
If the node to be deleted has two children, it must be replaced with its first in-order successor (not predecessor)
After deletion of the desired node, the tree must be rebalanced if necessary
Your function must return a pointer to the new root node of the tree after removing the desired value, and after rebalancing
Your files 14-binary_tree_balance.c, 103-binary_tree_rotate_left.c and 104-binary_tree_rotate_right.c will be compiled during the correction



## 124-sorted_array_to_avl.c, 0-binary_tree_node.c ##
Write a function that builds an AVL tree from an array

Prototype: avl_t *sorted_array_to_avl(int *array, size_t size);
Where array is a pointer to the first element of the array to be converted
And size is the number of element in the array
Your function must return a pointer to the root node of the created AVL tree, or NULL on failure
You can assume there will be no duplicate value in the array
You are not allowed to rotate
You can only have 2 functions in your file
Your file 0-binary_tree_node.c will be compiled during the correction



## 125-O ##
What are the average time complexities of those operations on an AVL Tree (one answer per line):

Inserting the value n
Removing the node with the value n
Searching for a node in an AVL tree of size n



## 130-binary_tree_is_heap.c ##
Write a function that checks if a binary tree is a valid Max Binary Heap

Prototype: int binary_tree_is_heap(const binary_tree_t *tree);
Where tree is a pointer to the root node of the tree to check
Your function must return 1 if tree is a valid Max Binary Heap, and 0 otherwise
If tree is NULL, return 0
Properties of a Max Binary Heap:

It’s a complete tree
In a Max Binary Heap, the value at root must be maximum among all values present in Binary Heap
The last property must be recursively true for all nodes in Binary Tree




## 131-heap_insert.c, 0-binary_tree_node.c ##
Write a function that inserts a value in Max Binary Heap

Prototype: heap_t *heap_insert(heap_t **root, int value)
Where root is a double pointer to the root node of the Heap to insert the value
And value is the value to store in the node to be inserted
Your function must return a pointer to the created node, or NULL on failure
If the address stored in root is NULL, the created node must become the root node.
You have to respect a Max Heap ordering
You are allowed to have up to 6 functions in your file
Your file 0-binary_tree_node.c will be compiled during the correction



## 132-array_to_heap.c, 131-heap_insert.c, 0-binary_tree_node.c ##
Write a function that builds a Max Binary Heap tree from an array

Prototype: heap_t *array_to_heap(int *array, size_t size);
Where array is a pointer to the first element of the array to be converted
And size is the number of element in the array
Your function must return a pointer to the root node of the created Binary Heap, or NULL on failure
Your files 131-heap_insert.c and 0-binary_tree_node.c will be compiled during the correction



## 133-heap_extract.c ##
Write a function that extracts the root node of a Max Binary Heap

Prototype: int heap_extract(heap_t **root);
Where root is a double pointer to the root node of heap
Your function must return the value stored in the root node
The root node must be freed and replace with the last level-order node of the heap
Once replaced, the heap must be rebuilt if necessary
If your function fails, return 0


## 134-heap_to_sorted_array.c, 133-heap_extract.c ##
Write a function that converts a Binary Max Heap to a sorted array of integers

Prototype: int *heap_to_sorted_array(heap_t *heap, size_t *size);
Where heap is a pointer to the root node of the heap to convert
And size is an address to store the size of the array
You can assume size is a valid address
Since we are using Max Heap, the returned array must be sorted in descending order
Your file 133-heap_extract.c will be compile during the correction




## 135-O ##
What are the average time complexities of those operations on a Binary Heap (one answer per line):

Inserting the value n
Extracting the root node
Searching for a node in a binary heap of size n
