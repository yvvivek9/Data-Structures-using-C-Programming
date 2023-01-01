typedef struct double_linked_list{
    int data;
    struct double_linked_list* next;
    struct double_linked_list* prev;
}dll;

dll* insert_dll(dll* head, int data, int pos);
dll* find_data_dll(dll* head, int data);
dll* find_pos_dll(dll* head, int data);
dll* delete_dll(dll* head, dll* node);
void update_dll(dll* node, int data);
int length_dll(dll* head);
void terminate_dll(dll* head);
void display_dll(dll* head);
void driver_dll();



