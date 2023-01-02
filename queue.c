#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue* init_queue(queue* que, int size)
{
    que = (queue*)malloc(sizeof(queue));
    que->arr = (int*)malloc(size*sizeof(int));
    que->front = -1; que->rear = -1;
    que->size = size;
    return que;
}

void sort_queue(queue* que)
{
    int* arr = (int*)malloc(sizeof(int)*que->size);
    int size = que->front - que->rear;
    for(int i = 0; i < size; i++)
        arr[i] = que->arr[++que->rear];
    que->arr = arr;
    que->rear = -1;
    que->front = size - 1;
}

void enqueue(queue* que, int data)
{
    if(que->front == que->size - 1 && que->rear == -1){
        printf("Queue overflow!\n");
    }
    else if(que->front == que->size - 1){
        sort_queue(que);
        que->arr[++que->front] = data;
        printf("Data inserted....\n");
    }
    else{
        que->arr[++que->front] = data;
        printf("Data inserted....\n");
    }
}

void dequeue(queue* que)
{
    if(que->rear == que->size - 1)
        printf("Queue underflow!\n");
    else
        printf("Dequeued data: %d\n", que->arr[++que->rear]);
}

void display_queue(queue* que)
{
    if(que->front == -1)
        printf("Queue is empty....\n");
    else{
        printf("Data in queue: ");
        for(int i = que->rear; i < que->front;)
            printf("%d ", que->arr[++i]);
        printf("\n");
    }
}

void terminate_queue(queue* que)
{
    free(que->arr);
    free(que);
}

void driver_queue()
{
    int terminate = 1;
    int size;
    int data;
    int ch;
    printf("\nEnter size of queue to be created: ");
    scanf("%d", &size);
    queue* que = init_queue(que, size);
    while(terminate){
        printf("\n[1] Enqueue\n");
        printf("[2] Dequeue\n");
        printf("[3] Display Queue\n");
        printf("[0] Delete queue and go back\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 0:
                terminate_queue(que);
                terminate = 0;
                break;
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(que, data);
                break;
            case 2:
                dequeue(que);
                break;
            case 3:
                display_queue(que);
                break;
        }
    }
}