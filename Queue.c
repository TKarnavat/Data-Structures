/*
    TOPIC: Queues
    DESCRIPTION: Here we cover Queue data structure. How elements are added and removed from the Queue.
                Ex:     Queue: 5 7 2 
                        Remove -> 5
                        Queue: 7 2 
                        Add: 22 34
                        Queue: 7 2 22 34 
                        Remove -> 7
                        Queue: 2 22 34 
*/

#include <stdio.h>

#define QUEUE_SIZE 10

int Queue[QUEUE_SIZE];      //Global Queue
int First = 0, Last = 0;    //Global var to track first and last entry


// Add an element to the queue
void Add(int var)
{
    Queue[Last++] = var;
}

// Remove an element from the queue
int Remove()
{
    int first_element;
    int j=0;

    if(Last == 0)
    {
        return 0;
    }

    first_element = Queue[First];

    // Shifts all the elements by 1 replacing first element. O(n) time
    for(int i=0; i<Last; i++)
    {
        Queue[j] = Queue[j+1];
        ++j;
    }
     --Last;
    
    return first_element;
}

// Print the entire Queue
void PrintQueue()
{
    printf("Queue: ");
    for(int i=0; i<Last; i++)
    {
        printf("%d ", Queue[i]);
    }
    printf("\n");
}


int main()
{
    int value_removed;

    value_removed = Remove();   //Should give Error as Queue is already empty
    if(value_removed ==0){printf("Error: Empty Queue\n");}
    else{printf("Value removed: %d\n", value_removed);}

    Add(5);     //Add 3 values to Queue: 5,7,2
    Add(7);
    Add(2);
    
    PrintQueue();
    value_removed = Remove();   //Removes first value inserted (5)
    if(value_removed ==0){printf("Error: Empty Queue\n");}
    else{printf("Value removed: %d\n", value_removed);}

    PrintQueue();               //Prints 7,2
    Add(22);                    //Add 22 and 34 to Queue
    Add(34);
    PrintQueue();               //Prints 7,2,22,34
    value_removed = Remove();
    printf("Value removed: %d\n", value_removed);
    PrintQueue();               //Prints 2,22,34 VOILA
}