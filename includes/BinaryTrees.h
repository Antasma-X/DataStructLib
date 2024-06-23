#ifndef BINARYTREES_H
#define BINARYTREES_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

//Change Macros for different data types
#define TYPEOFTREE int
#define MININTREE INT_MIN
#define MAXINTREE INT_MAX

// Almost all functions assume that the tree is a Binary Search Tree

//Binary Tree Node
struct BT_Node{
    struct BT_Node* left;
    TYPEOFTREE data;
    struct BT_Node* right;
};

//Creates a Binary Tree Node and initializes the variables
struct BT_Node* BT_CreateNewNode(TYPEOFTREE data);

//Compares data. If the data being inserted is greater than 0 is returned. Otherwise 1 is returned (If TYPEOFTREE is not defined as int, function should be altered)
int BT_Compare(TYPEOFTREE dataInTree, TYPEOFTREE dataBeingInserted);

//Inserts Node in tree(Assuming Tree is Binary Search Tree) recursively
struct BT_Node* BT_Insert(struct BT_Node* root, TYPEOFTREE data);

//Inserts Node in tree(Assuming Tree is Binary Search Tree) iteratively
struct BT_Node* BT_InsertIterative(struct BT_Node* root, TYPEOFTREE data);

//Returns Address of Minimum Value in tree
struct BT_Node* BT_MinAddr(struct BT_Node* root);

//Returns Minimum Value in tree
int BT_Min(struct BT_Node* root);

//Returns Address of Maximum Value in tree
struct BT_Node* BT_MaxAddr(struct BT_Node* root);

//Returns Maximum Value in tree
int BT_Max(struct BT_Node* root);

//Checks if Value is in Tree
int BT_isValueInTree(struct BT_Node* root, TYPEOFTREE data);

//Gets Address of first instance of data found in tree
struct BT_Node* BT_GetAddress(struct BT_Node* root, TYPEOFTREE data);

//Checks if tree is strict tree
int BT_IsStrictTree(struct BT_Node* root);

//For Preorder, order = -1
//For Inorder, order = 0 
//For Postorder, order = 1
//Traverses List in preorder, inorder or postorder and performs function of progammer's choice on the value in the node. The function must have void return type, and take a void* pointer, Binary Tree Node pointer and data of tree(while tree is being traversed, the data being accessed will passed into the function).You also pass in a void * variable that will passed into the function
void BT_OrderTraversal(struct BT_Node* root, int order, void (*func)(void*,struct BT_Node*, TYPEOFTREE), void* var);

//Function is called everytime Order Traversal Function access a piece of data in tree, counting the number of nodes.
void numberOfNodesUtil(void* n, struct BT_Node* root,  TYPEOFTREE data);

//Returns Number of Nodes in Tree using the Order Traversal function. I use weird void* hacks that even I don't understand and pass in numberOfNodesUtil into the traversal function. The traversal function is done in order
int BT_NumberOfNodes(struct BT_Node* root);

//Frees every node in tree using order traversal function. When node is accessed, node is freed using util function
void BT_DeleteTree(struct BT_Node* root);

//Deletes first Node with passed in value and replaces the node with minimum value in right sub tree
struct BT_Node* BT_DeleteNode(struct BT_Node* root, TYPEOFTREE data);

//Finds height of tree
int BT_FindHeight(struct BT_Node* root);

//Basically wrapper function for BT_isBSTUtil
int BT_IsBST(struct BT_Node* root);

//Checks if tree is perfect. Since a perfect tree would have 2^h+1 -1 nodes if h is height, number of nodes should be equal to 2^h+1 -1
int BT_IsPerfectTree(struct BT_Node* root);

//Finds next node in Inorder Succession (Finds the next node in ascending order)
struct BT_Node* BT_FindNextNodeInOrderSuccession(struct BT_Node* root, int data);

#endif