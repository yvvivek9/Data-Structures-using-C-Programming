typedef struct stacks{
    int top;
    int size;
    int* arr;
}stacks;

stacks* init_stack(stacks* stack, int size);
void push_stack(stacks* stack, int data);
int pop_stack(stacks* stack);
int top_stack(stacks* stack);
void display_stack(stacks* stack);
void driver_stack();
void terminate_stack(stacks* stack);