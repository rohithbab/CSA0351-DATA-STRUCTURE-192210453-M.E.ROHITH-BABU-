#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %d.\n", value);
        return;
    }
    s->items[++s->top] = value;
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->items[s->top--];
}

int main() {
    struct Stack stack1, stack2;
    initialize(&stack1);
    initialize(&stack2);

    // Push elements to stack1 and stack2 (for demonstration purposes)
    for (int i = 1; i <= 5; i++) {
        push(&stack1, i);
        push(&stack2, i + 5);
    }

    // Transfer elements from stack1 to stack2 (except the bottom element)
    int numElementsToTransfer = stack1.top;
    for (int i = 0; i < numElementsToTransfer; i++) {
        int element = pop(&stack1);
        push(&stack2, element);
    }

    // Get the bottom element from stack1 and the top element from stack2
    int bottomElement = pop(&stack1);
    int topElement = stack2.items[stack2.top];

    // Perform the addition and print the result
    int result = bottomElement + topElement;
    printf("Result: %d\n", result);

    return 0;
}
