/*
    TOPIC: Stack
    DESCRIPTION: Here we cover the working of Stack data structure using both arrays and linked lists
                 Ex: 44 15 8 1 
                     Top val is: 44
                     POPPED
                     POPPED
                     8 1 
                     Top val is: 8

*/

#include <stdio.h>
#include <stdlib.h>

//============================= Stack Using Array ===============================
#define MAX_SIZE 100
int stack[MAX_SIZE];    
int top = -1;            //Global var tracking top most value

void Push(int val)
{
    stack[++top] = val;
}

void Pop()
{
    if(top < 0)
    {
        printf("Popping Error: Stack is already empty\n");
    }
    //Simply move the index one down, top value will be overwritten next Push
    top--;
    printf("POPPED\n");
}

int GetTop()
{
    return stack[top];
}

void PrintStack()
{
    printf("Stack (Arrays): ");
    for(int i=top; i>=0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

//========================== Stack Using Linked List ============================

struct Node
{
    int val;
    struct Node* next;
};

struct Node* head;

//Push value at the beginning (Top) of the Linked List 
void PushNode(int val) 
{
    struct Node* node = malloc(sizeof(struct Node));

    node->val = val;
    node->next = head;
    head = node;
}

void PopNode()
{
    struct Node* top;

    top = head;
    head = head->next;
    //delete top value/node
    free(top);  
    printf("POPPED\n");
}

int GetTopNode()
{
    return head->val;
}

void PrintLL()
{
    struct Node* node;
    node = head;

    printf("Stack (Linked List): ");
    while(node != NULL)
    {
        printf("%d ", node->val);
        node = node->next;
    }    
    printf("\n");
}

int main()
{
    //  **COMMENT THIS OUT TO SEE STACK EXECUTION USING ARRAYS**
    /*
    int top_val;

    Push(1);    //Bottom most value in the stack
    Push(8);
    Push(15);
    Push(44);

    PrintStack();
    top_val=GetTop();
    printf("Top val is: %d\n", top_val);

    Pop();
    Pop();

    PrintStack();
    top_val=GetTop();
    printf("Top val is: %d\n", top_val);
    */
   
   //  **STACK EXECUTION USING LINKED LIST**

    int top_node;

    PushNode(1);
    PushNode(8);
    PushNode(15);
    PushNode(44);

    PrintLL();
    top_node = GetTopNode();
    printf("Top node val is: %d\n", top_node);

    PopNode();
    PopNode();

    PrintLL();
    top_node = GetTopNode();
    printf("Top node val is: %d\n", top_node);

    return 0;
}
