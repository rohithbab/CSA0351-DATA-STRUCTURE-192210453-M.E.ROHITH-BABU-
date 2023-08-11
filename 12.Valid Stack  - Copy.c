#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
    char data;
    struct Stack *next;
};

struct Stack *newNode(char data) {
    struct Stack *node = (struct Stack *)malloc(sizeof(struct Stack));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(struct Stack **top, char data) {
    struct Stack *node = newNode(data);
    node->next = *top;
    *top = node;
}

char pop(struct Stack **top) {
    if (*top == NULL) {
        printf("Stack underflow!\n");
        exit(1);
    }
    struct Stack *temp = *top;
    char data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

bool isValidStack(char *sequence) {
    struct Stack *top = NULL;

    for (int i = 0; sequence[i] != '\0'; i++) {
        char current = sequence[i];

        if (current == '(' || current == '{' || current == '[') {
            push(&top, current);
        } else if (current == ')' || current == '}' || current == ']') {
            if (top == NULL) {
                return false;  
            }

            char topChar = pop(&top);

            if ((current == ')' && topChar != '(') ||
                (current == '}' && topChar != '{') ||
                (current == ']' && topChar != '[')) {
                return false;  
            }
        }
    }

    return top == NULL; 
}

int main() {
    char sequence[100];
    printf("Enter a sequence of parentheses: ");
    scanf("%s", sequence);

    if (isValidStack(sequence)) {
        printf("The sequence is a valid stack.\n");
    } else {
        printf("The sequence is not a valid stack.\n");
    }

    return 0;
}

