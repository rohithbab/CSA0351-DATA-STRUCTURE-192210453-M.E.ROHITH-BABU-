#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

int getListLength(struct ListNode* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct ListNode* findIntersection(struct ListNode* head1, struct ListNode* head2) {
    int len1 = getListLength(head1);
    int len2 = getListLength(head2);
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        for (int i = 0; i < diff; i++) {
            head1 = head1->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            head2 = head2->next;
        }
    }
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1; // Intersection found
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL; // No intersection
}

int main() {
    struct ListNode* common = (struct ListNode*)malloc(sizeof(struct ListNode));
    common->data = 8;
    
    struct ListNode* head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head1->data = 1;
    head1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head1->next->data = 2;
    head1->next->next = common;

    struct ListNode* head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head2->data = 3;
    head2->next = common;

    common->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    common->next->data = 4;
    common->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    common->next->next->data = 5;
    common->next->next->next = NULL;

    struct ListNode* intersection = findIntersection(head1, head2);

    if (intersection != NULL) {
        printf("Intersection point: %d\n", intersection->data);
    } else {
        printf("No intersection\n");
    }

    free(common->next->next);
    free(common->next);
    free(head2);
    free(head1->next);
    free(head1);

    return 0;
}