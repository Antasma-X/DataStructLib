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
struct BT_Node* BT_CreateNewNode(TYPEOFTREE data){
    struct BT_Node* newNode = (struct BT_Node*) malloc(sizeof(struct BT_Node));
    newNode -> left = NULL;
    newNode -> data = data;
    newNode -> right = NULL;
    return newNode;
}

//Compares data. If the data being inserted is greater than 0 is returned. Otherwise 1 is returned (If TYPEOFTREE is not defined as int, function should be altered)
int BT_Compare(TYPEOFTREE dataInTree, TYPEOFTREE dataBeingInserted){

    if (dataBeingInserted<=dataInTree){
        return 1;
    }
    else{
        return 0;
    }
}

//Inserts Node in tree(Assuming Tree is Binary Search Tree) recursively
struct BT_Node* BT_Insert(struct BT_Node* root, TYPEOFTREE data){

    if (root==NULL){
        struct BT_Node* newNode = BT_CreateNewNode(data);
        root=newNode;
    }
    
    else if (BT_Compare(root->data,data)){
        root->left=BT_Insert(root->left,data);
    }
    else {
        root->right=BT_Insert(root->right,data);
    }
    return root;
}

//Inserts Node in tree(Assuming Tree is Binary Search Tree) iteratively
struct BT_Node* BT_InsertIterative(struct BT_Node* root, TYPEOFTREE data){
    struct BT_Node* newNode = BT_CreateNewNode(data);
    if (root==NULL){
        root=newNode;
    }
    else {
        struct BT_Node* current = root;

        while(1){
            if (BT_Compare(current->data,data)){
                if(current->left != NULL){
                    current=current->left;
                }
                else{ 
                    current->left =newNode;
                    break;
                }
            }
            else{
                if(current->right != NULL){
                    current=current->left;
                }
                else{
                    current->right=newNode;
                    break;
                }
            }
            
        }
    }
    return root;
}

//Returns Address of Minimum Value in tree
struct BT_Node* BT_MinAddr(struct BT_Node* root){

    while(root->left !=NULL){
        root=root->left;
    }
    return root;
}

//Returns Minimum Value in tree
int BT_Min(struct BT_Node* root){
    return BT_MinAddr(root)->data;
}

//Returns Address of Maximum Value in tree
struct BT_Node* BT_MaxAddr(struct BT_Node* root){

    while(root->right !=NULL){
        root=root->right;
    }
    return root;
}

//Returns Maximum Value in tree
int BT_Max(struct BT_Node* root){
    return BT_MaxAddr(root)->data;
}

//Checks if Value is in Tree
int BT_isValueInTree(struct BT_Node* root, TYPEOFTREE data){

    if(root==NULL){
        return 0;
    }
    else if (root->data==data){
        return 1;
    }
    else if(BT_Compare(root->data,data)){
        return BT_isValueInTree(root->left,data);
    }
    else{
        return BT_isValueInTree(root->right,data);
    }
}

//Gets Address of first instance of data found in tree
struct BT_Node* BT_GetAddress(struct BT_Node* root, TYPEOFTREE data){
    if (root->data==data){
        return root;
    }
    else if(BT_Compare(root->data,data)){
        return BT_GetAddress(root->left,data);
    }
    else{
        return BT_GetAddress(root->right,data);
    }  
}

//Checks if tree is strict tree
int BT_IsStrictTree(struct BT_Node* root){
    if (root->left == NULL && root->right == NULL){
        return 1;
    }
    else if ((root->left == NULL && root->right != NULL)||(root->left != NULL && root->right == NULL)){
        return 0;
    }
    else if(root->left != NULL && root->right != NULL){
        return BT_IsStrictTree(root->left) && BT_IsStrictTree(root->right);
    }
}

//For Preorder, order = -1
//For Inorder, order = 0 
//For Postorder, order = 1
//Traverses List in preorder, inorder or postorder and performs function of progammer's choice on the value in the node. The function must have void return type, and take a void* pointer, Binary Tree Node pointer and data of tree(while tree is being traversed, the data being accessed will passed into the function).You also pass in a void * variable that will passed into the function
void BT_OrderTraversal(struct BT_Node* root, int order, void (*func)(void*,struct BT_Node*, TYPEOFTREE), void* var){

    if (root==NULL){
        return;
    }

    //Traversal
    if (order==-1){
        func(var,root,root->data);
    }

    BT_OrderTraversal(root->left,order,func,var);

    if(order==0){
        func(var,root,root->data);      
    }

    BT_OrderTraversal(root->right,order,func,var);

    if(order==1){
        func(var,root,root->data);
    }
}

//Function is called everytime Order Traversal Function access a piece of data in tree, counting the number of nodes.
void numberOfNodesUtil(void* n, struct BT_Node* root,  TYPEOFTREE data){
    int* number=(int*) n;
    (*number)++;

}

//Returns Number of Nodes in Tree using the Order Traversal function. I use weird void* hacks that even I don't understand and pass in numberOfNodesUtil into the traversal function. The traversal function is done in order
int BT_NumberOfNodes(struct BT_Node* root){
    int n=0;
    BT_OrderTraversal(root,0,numberOfNodesUtil,&n);
    return n;
}

//Basically just wrapper function for free() because Order Traversal requires void (func*) (void*, struct BT_Node*, TYPEOFTREE data) function to passed in
void deleteTreeUtil(void* null, struct BT_Node* node, TYPEOFTREE data){
    free(node);
}

//Frees every node in tree using order traversal function. When node is accessed, node is freed using util function
void BT_DeleteTree(struct BT_Node* root){
    BT_OrderTraversal(root,0,deleteTreeUtil,NULL);
}

//Deletes first Node with passed in value and replaces the node with minimum value in right sub tree
struct BT_Node* BT_DeleteNode(struct BT_Node* root, TYPEOFTREE data){
    
    if (root==NULL){
        root=NULL;
    }
    else if (data>root->data){
        root->right=BT_DeleteNode(root->right,data);
    }
    else if(data<root->data){
        root->left=BT_DeleteNode(root->left,data);
    }
    
    else{
        if(root->left == NULL && root->right==NULL){
            free(root);
            root=NULL;
        }
        else if (root->left !=NULL && root->right ==NULL){
            struct BT_Node* temp=root->left;
            free(root);
            root=temp;
        }
        else if (root->left == NULL && root->right != NULL){
            struct BT_Node* temp=root->right;
            free(root);
            root=temp;        
        }
        else {
            TYPEOFTREE temp= BT_Min(root->right);
            root->data=temp;
            root->right=BT_DeleteNode(root->right,data);

        }
    }
    return root;
}

//Finds height of tree
int BT_FindHeight(struct BT_Node* root){

    if (root==NULL){
        return -1;
    }
    else{
        int leftHeight= BT_FindHeight(root->left);
        int rightHeight= BT_FindHeight(root->right);

        if (leftHeight>rightHeight){
            return leftHeight +1;
        }
        else {
            return rightHeight +1;
        }
    }
}

//Checks if tree is Binary Search Tree by making sure the values in the tree are in the correct range recursively
int BT_isBSTUtil(struct BT_Node* root,TYPEOFTREE minValue, TYPEOFTREE maxValue){

    if (root==NULL){
        return 1;
    }
    else if(BT_Compare(root->data,minValue) && (!BT_Compare(root->data,maxValue)) && BT_isBSTUtil(root->left,minValue,root->data) && BT_isBSTUtil(root->right,root->data,maxValue)){
        return 1;
    }
    else {
        return 0;
    }
}

//Basically wrapper function for BT_isBSTUtil
int BT_IsBST(struct BT_Node* root){
    return BT_isBSTUtil(root,MININTREE,MAXINTREE);
}

//Checks if tree is perfect. Since a perfect tree would have 2^h+1 -1 nodes if h is height, number of nodes should be equal to 2^h+1 -1
int BT_IsPerfectTree(struct BT_Node* root){ 
    int n = BT_NumberOfNodes(root);
    int h = BT_FindHeight(root);

    if(n==pow(2,h+1)+1){
        return 1;
    }
    else{
        return 0;
    }
}

//Finds next node in Inorder Succession (Finds the next node in ascending order)
struct BT_Node* BT_FindNextNodeInOrderSuccession(struct BT_Node* root, int data){

    struct BT_Node* node=BT_GetAddress(root,data);

    if(node->right != NULL){
        return BT_MinAddr(root->right);
    }
    else {
        struct BT_Node* successor = NULL;
        while (root != node){
            if(node->data<root->data){
                successor = root;
                root=root->left;
            }
            else{

                root=root->right;
            }
        }  
        return successor;   
    }
}
