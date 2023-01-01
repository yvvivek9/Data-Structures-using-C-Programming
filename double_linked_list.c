#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

dll* insert_dll(dll* head, int data, int pos)
{
    dll* to_be_returned = head;
    dll* new = (dll*)malloc(sizeof(dll));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    if(head == NULL & pos == 1){
        return new;
    }
    else if(head != NULL && pos == 1){
        head->prev = new;
        new->next = head;
        return new;
    }
    else if(head != NULL & pos == 0){
        while(head->next != NULL)
            head = head->next;
        head->next = new;
        new->prev = head;
        return to_be_returned;
    }
    else if(head != NULL & pos <= length_dll(head)){
        while(pos > 2){
            head = head->next;
            pos--;
        }
        head->next->prev = new;
        new->next = head->next;
        head->next = new;
        new->prev = head;
        return to_be_returned;
    }
    else{
        printf("Invalid Entry... \n");
        return to_be_returned;
    }
}

dll* find_data_dll(dll* head, int data)
{
    while(head != NULL){
        if(head->data == data)
            return head;
        head = head->next;
    }
    if(head == NULL){
        printf("Data not found... \n");
        return NULL;
    }
}

dll* find_pos_dll(dll* head, int pos)
{
    if(pos <= length_dll(head)){
        while(pos > 1){
            head = head->next;
            pos--;
        }
        return head;
    }
    else{
        printf("Invalid Position... \n");
        return NULL;
    }
}

dll* delete_dll(dll* head, dll* node)
{
    if(head == node){
        if(node->next == NULL){
            free(node);
            return NULL;
        }
        else{
            dll* to_be_returned = node->next;
            free(node);
            return to_be_returned;
        }
    }
    else{
        if(node->next == NULL){
            node->prev->next = NULL;
            free(node);
        }
        else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
            free(node);
        }
        return head;
    }
}

void update_dll(dll* node, int data)
{
    node->data = data;
}

int length_dll(dll* head)
{
    int length = 0;
    while(head != NULL){
        head = head->next;
        length++;
    }
    return length;
}

void terminate_dll(dll* head)
{
    if(head != NULL){
        terminate_dll(head->next);
        free(head);
    }
}

void display_dll(dll* head)
{
    printf("Length: %d\n", length_dll(head));
    printf("Contents: ");
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("\n");
}

void driver_dll()
{
    printf("\n");
    dll* head = NULL;
    int terminate = 1;
    int ch;
    int data; int pos;
    while(terminate){
        printf("\n[1] Insert\n");
        printf("[2] Delete a Node\n");
        printf("[3] Update a node\n");
        printf("[4] Display List\n");
        printf("[0] Delete the list and go back\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 0:
                terminate_dll(head);
                terminate = 0;
                break;
            case 1:
                printf("\nEnter data and position (0 to insert at end): ");
                scanf("%d %d", &data, &pos);
                head = insert_dll(head, data, pos);
                break;
            case 2:
                printf("\n[1] Delete based on position");
                printf("\n[2] Delete based on data\nEnter your choice: ");
                scanf("%d", &ch);
                switch(ch){
                    case 1:
                        printf("Enter pos to be deleted: ");
                        scanf("%d", &pos);
                        if(find_pos_dll(head, pos) != NULL)
                            head = delete_dll(head, find_pos_dll(head, pos));
                        break;
                    case 2:
                        printf("Enter data to be deleted: ");
                        scanf("%d", &data);
                        if(find_data_dll(head, data) != NULL)
                            head = delete_dll(head, find_data_dll(head, data));
                        break;
                }
                break;
            case 3:
                printf("\n[1] Update based on position");
                printf("\n[2] Update based on data\nEnter your choice: ");
                scanf("%d", &ch);
                switch(ch){
                    case 1:
                        printf("Enter pos to be updated: ");
                        scanf("%d", &pos);
                        if(find_pos_dll(head, pos) != NULL){
                            printf("Enter updated data: ");
                            scanf("%d", &data);
                            update_dll(find_pos_dll(head, pos), data);
                        }
                        break;
                    case 2:
                        printf("Enter data to be updated: ");
                        scanf("%d", &data);
                        dll* node = find_data_dll(head, data);
                        if(node != NULL){
                            printf("Enter updated data: ");
                            scanf("%d", &data);
                            update_dll(node, data);
                        }
                        break;
                }
                break;
            case 4:
                display_dll(head);
                break;
        }
    }
}