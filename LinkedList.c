/*
    TOPIC: Linked List
    DESCRIPTION: Here we cover how to create, traverse and delete nodes in a LinkedList
                 Ex: [Val1]-->[Val2]-->[Val3]-->[Val4]-->[Val5]-->NULL
                     Deleted Node [Val2]
                     [Val1]-->[Val3]-->[Val4]-->[Val5]-->NULL
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node* next;
};

//Global so we don't have to pass the head address everytime in functions
struct Node* head;


//Insert a node at the beginning of the Linked List
void InsertNode(int val) 
{
    struct Node* node = malloc(sizeof(struct Node));

    node->val = val;
    node->next = head;
    head = node;
}

//Delete a node given its value
void DeleteNode(int val)
{
    struct Node* prev;
    struct Node* current;

    if(head->val == val)
    {
        current = head;
        head = head->next;

        printf("Deleted Node with val: %d\n", current->val);
        free(current);
        return;
    }

    current = head->next;
    prev = head;

    while(current != NULL)
    {
        //Delete the node
        if(current->val == val)
        {
            prev->next = current->next;
            printf("Deleted Node [%d]\n", current->val);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    if(current == NULL)
    {
        printf("Node [%d] not found\n", val);
    }
}

//Print all the nodes in the LinkedList
void PrintList()
{
    struct Node* node;
    node = head;
    while(node != NULL)
    {
        printf("[%d]-->", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

int main()
{

    InsertNode(10);
    InsertNode(2);
    InsertNode(20);
    InsertNode(6);
    InsertNode(25);
    
    PrintList();

    DeleteNode(123);
    DeleteNode(2);

    PrintList();
    return 0;
}