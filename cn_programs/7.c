// C program for array implementation of queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a queue
struct Queue
{
	int front, rear, size;
	unsigned capacity;
	int* array;
};

// function to create a queue of given capacity. 
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0; 
	queue->rear = capacity - 1; // This is important, see the enqueue
	queue->array = (int*) malloc(queue->capacity * sizeof(int));
	return queue;
}

// Queue is full when size becomes equal to the capacity 
int isFull(struct Queue* queue)
{ return (queue->size == queue->capacity); }

// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{ return (queue->size == 0); }

// Function to add an item to the queue. 
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1)%queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue. 
// It changes front and size
int dequeue(struct Queue* high_queue,struct Queue* low_queue)
{
	if (isEmpty(high_queue))
    {
        if (isEmpty(low_queue))
        {
            return INT_MIN;            
        }
        int item = low_queue->array[low_queue->front];
	    low_queue->front = (low_queue->front + 1)%low_queue->capacity;
	    low_queue->size = low_queue->size - 1;
	    return item;
    }
		
	int item = high_queue->array[high_queue->front];
	high_queue->front = (high_queue->front + 1)%high_queue->capacity;
	high_queue->size = high_queue->size - 1;
	return item;
}

// Function to get front of queue
int front(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

void display(struct Queue* high_queue,struct Queue* low_queue)
{
    int i;
	if (isEmpty(high_queue))
    {
        if (isEmpty(low_queue))
        {
            printf("both the queues are empty");            
        }
        printf("high priority queue is empty");
        printf("low priority Queue is : \n");
        for (i = low_queue->front; i <= (low_queue->rear)%low_queue->capacity; i++)
            printf("%d ", low_queue->array[i]);
        printf("\n");
	return;
    }	
	printf("\nhigh priority Queue is : \n");
        for (i = high_queue->front; i <= (high_queue->rear)%high_queue->capacity; i++)
            printf("%d ", high_queue->array[i]);
if (isEmpty(low_queue))
        {
            printf("\nlow priority queues is empty\n");            
	return;
        }
    printf("\n");
    printf("low priority Queue is : \n");
        for (i = low_queue->front; i <= (low_queue->rear)%low_queue->capacity; i++)
            printf("%d ", low_queue->array[i]);
    printf("\n");
}


// Driver program to test above functions./
int main()
{
	struct Queue* high_queue = createQueue(1000);
    struct Queue* low_queue = createQueue(1000);
    
    int choice,value,pri;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: printf("enter the element and priority :- ");scanf("%d %d",&value,&pri);
            if(pri==1)
                enqueue(high_queue, value);
            else
	            enqueue(low_queue, value);
            break;
            case 2:
                printf("%d dequeued from queue\n", dequeue(high_queue,low_queue));
            break;
            case 3:
            display(high_queue,low_queue);
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        } /*End of switch*/
    } /*End of while*/
	return 0;
}