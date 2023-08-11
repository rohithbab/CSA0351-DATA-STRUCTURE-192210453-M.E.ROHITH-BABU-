#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct Stack {
    struct Queue* q1;
    struct Queue* q2;
};

struct QueueNode* createQueueNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int data) {
    struct QueueNode* newNode = createQueueNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = q->front->data;
    struct QueueNode* temp = q->front;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return data;
}

void push(struct Stack* s, int data) {
    enqueue(s->q1, data);
}

int pop(struct Stack* s) {
    if (s->q1->front == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    while (s->q1->front->next != NULL) {
        enqueue(s->q2, dequeue(s->q1));
    }
    int data = dequeue(s->q1);
    struct Queue* temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
    return data;
}

int main() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));

    push(stack, 4);

    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    
    free(stack->q1);
    free(stack->q2);
    free(stack);

    return 0;
}
