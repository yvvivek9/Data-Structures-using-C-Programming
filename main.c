#include "double_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n\t\t\tDATA STRUCTURES USING C\n\n");
    printf("\t- Created by Vivek YV\n");
    int ch;
    while(1){
        printf("\n\n\t[1] Double Linked List\n");
        printf("\t[2] Stacks\n");
        printf("\t[3] Queues\n");
        printf("\t[4] Binary Tree\n");
        printf("\t[5] Graphs \n");
        printf("\t[0] Exit\n");
        printf("\tEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 0:
                exit(0);
            case 1:
                driver_dll();
                break;
        }
    }
}