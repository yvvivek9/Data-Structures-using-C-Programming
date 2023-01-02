#include <stdio.h>
#include <stdlib.h>
#include "stacks.h"

stacks* init_stack(stacks* stack, int size)
{
    stack = (stacks*)malloc(sizeof(stacks));
    stack->top = -1;
    stack->size = size;
    stack->arr = (int*)malloc(size*sizeof(int));
    return stack;
}

void push_stack(stacks* stack, int data)
{
    if(stack->top == stack->size - 1){
        printf("Stack Overflow\n");
    }
    else{
        stack->arr[++stack->top] = data;
        printf("Pushed....\n");
    }
}

int pop_stack(stacks* stack)
{
    if(stack->top == -1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Popped element is %d\n", stack->arr[stack->top--]);
    }
}

int top_stack(stacks* stack)
{
    if(stack->top == -1)
        printf("Stack Empty!\n");
    else
        printf("Top element is %d\n", stack->arr[stack->top]);
}

void display_stack(stacks* stack)
{
    if(stack->top == -1)
        printf("Stack Empty!\n");
    else{
        printf("Data in stack: ");
        for(int i = stack->top; i >= 0; i--){
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

void terminate_stack(stacks* stack)
{
    free(stack->arr);
    free(stack);
}

void driver_stack()
{
    int ch; 
    int terminate = 1;
    int size; int data;
    printf("\nEnter size of Stack to be created: ");
    scanf("%d", &size);
    stacks* stack = init_stack(stack, size);
    while(terminate){
        printf("\n[1] Push to stack\n");
        printf("[2] Pop from stack\n");
        printf("[3] View Top of stack\n");
        printf("[4] Display entire stack\n");
        printf("[0] Delete stack and go back\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 0:
                terminate_stack(stack);
                terminate = 0;
                break;
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push_stack(stack, data);
                break;
            case 2:
                pop_stack(stack);
                break;
            case 3:
                top_stack(stack);
                break;
            case 4:
                display_stack(stack);
                break;
        }
    }
}