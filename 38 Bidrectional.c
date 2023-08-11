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

    // Perform bidirectional operation: Add bottom element of stack1 to top element of stack2
    int bottomElement = pop(&stack1);
    int topElement = stack2.items[stack2.top];
    int result = bottomElement + topElement;

    // Print the elements and result
    printf("Bottom Element: %d\n", bottomElement);
    printf("Top Element: %d\n", topElement);
    printf("Result: %d\n", result);

    return 0;
}
