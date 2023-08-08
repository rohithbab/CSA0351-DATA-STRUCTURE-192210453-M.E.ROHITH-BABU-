#include <stdio.h>

int main() {
    int i,array[100];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Odd values in the array: ");
    for (i = 0; i < size; i++) {
        if (array[i] % 2 != 0) {
            printf("%d ", array[i]);
        }
    }

    printf("\nEven values in the array: ");
    for (i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            printf("%d ", array[i]);
        }
    }

    printf("\n");

    return 0;
}

