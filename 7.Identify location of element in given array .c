#include <stdio.h>

int main() {
    int i,array[100];
    int size, searchElement;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &searchElement);

    int foundIndex = -1;

    for (i = 0; i < size; i++) {
        if (array[i] == searchElement) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("Element %d found at index %d.\n", searchElement, foundIndex);
    } else {
        printf("Element %d not found.\n", searchElement);
    }

    return 0;
}

