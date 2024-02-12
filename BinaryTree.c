/*
    TOPIC: Binary Search Tree
    DESCRIPTION: Here we cover how to create a BST using recursion and then 
                 traverse to find a value in the Tree.

                 Ex: Go left: Val = 5 , Node val = 10

                     Go left: Val = 2 , Node val = 10
                     Go left: Val = 2 , Node val = 5

                     Go left: Val = 4 , Node val = 10
                     Go left: Val = 4 , Node val = 5
                     Go right: Val = 4 , Node val = 2
*/

#include <stdio.h>
#include <stdlib.h>


struct TreeNode{
    int var;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* InsertNode(struct TreeNode* node, int val)
{
    if (node == NULL){
        struct TreeNode* addNode = malloc(sizeof(struct TreeNode));
        addNode->var = val;
        addNode->right = NULL;
        addNode->left = NULL;
        node = addNode;
    }
    else if(val <= node->var)
    {
        printf("Go left: Val = %d , Node val = %d\n", val, node->var);
        node->left = InsertNode(node->left, val);
    }
    else
    {
        printf("Go right: Val = %d , Node val = %d\n", val, node->var);
        node->right = InsertNode(node->right, val);
    }
    return node;
}

void FindNode(struct TreeNode* node, int val)
{

    if(node != NULL)
    {
        if(val == node->var)
        {
            printf("Found value: %d\n", val);
            return;
        }
        else if(val <= node->var)
        {
            FindNode(node->left, val);
        }
        else{
            FindNode(node->right, val);
        }
    }
    else{
        printf("Value not found\n");
    }
}


void PrintTree(struct TreeNode* node)
{
    if (node != NULL)
    {
        PrintTree(node->left);

        printf("%d ", node->var);

        PrintTree(node->right);
    }
}


int main()
{
    struct TreeNode* root = NULL;

    root = InsertNode(root,10);
    printf("\n");
    root = InsertNode(root,20);
    printf("\n");
    root = InsertNode(root,30);
    printf("\n");
    root = InsertNode(root,5);
    printf("\n");
    root = InsertNode(root,2);
    printf("\n");
    root = InsertNode(root,4);
    printf("\n");
    root = InsertNode(root,25);
    PrintTree(root);
    printf("\n");

    FindNode(root, 15);
    FindNode(root, 4);
    FindNode(root, 30);

}