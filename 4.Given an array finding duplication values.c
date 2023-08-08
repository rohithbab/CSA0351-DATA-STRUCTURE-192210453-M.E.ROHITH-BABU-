#include <stdio.h>

int main() {
    int arr[100];
    int i,j,size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Duplicate values in the array:\n");

    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                printf("%d\n", arr[i]);
                break;
            }
        }
    }

    return 0;
}

