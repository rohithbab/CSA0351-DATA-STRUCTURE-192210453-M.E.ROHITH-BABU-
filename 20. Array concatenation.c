#include <stdio.h>

int main() {
    int array1[] = {1, 2, 3};
    int array2[] = {4, 5, 6};

    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int newSize = size1 + size2;

    int concatenated[newSize];

    for (int i = 0; i < size1; i++) {
        concatenated[i] = array1[i];
    }

    for (int i = 0; i < size2; i++) {
        concatenated[size1 + i] = array2[i];
    }

    printf("Concatenated array: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", concatenated[i]);
    }
    printf("\n");

    return 0;
}

