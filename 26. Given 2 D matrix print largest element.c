#include <stdio.h>

#define ROWS 3
#define COLS 4

int findLargestElement(int matrix[ROWS][COLS]) {
    int largest = matrix[0][0]; 

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] > largest) {
                largest = matrix[i][j];
            }
        }
    }

    return largest;
}

int main() {
    int matrix[ROWS][COLS] = {
        {10, 25, 17, 8},
        {32, 12, 6, 19},
        {4, 51, 9, 23}
    };

    int largestElement = findLargestElement(matrix);
    printf("The largest element in the matrix is: %d\n", largestElement);

    return 0;
}

