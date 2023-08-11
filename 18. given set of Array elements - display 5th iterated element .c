#include <stdio.h>

int main() {
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int fifthElement;
    if (sizeof(array) / sizeof(array[0]) >= 5) {
        fifthElement = array[4]; // Arrays are zero-indexed
        printf("The 5th element is: %d\n", fifthElement);
    } else {
        printf("The array doesn't have enough elements.\n");
    }

    return 0;
}

