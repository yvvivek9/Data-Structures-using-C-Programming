typedef struct queue{
    int front;
    int rear;
    int size;
    int* arr;
}queue;

queue* init_queue(queue* que, int size);
void sort_queue(queue* que);
void enqueue(queue* que, int data);
void dequeue(queue* que);
void display_queue(queue* que);
void terminate_queue(queue* que);
void driver_queue();