#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Linked list: ");
    printList(head);

    int nodeCount = countNodes(head);
    printf("Number of nodes in the linked list: %d\n", nodeCount);

    return 0;
}

