#include <stdio.h>

void increment_repeated_twice(int arr[], int length, int increment_amount) {
    // Loop through the array and find elements repeated twice
    for (int i = 0; i < length; i++) {
        int count = 1; // Count the current element
        if (arr[i] == -1) {
            continue; // Element already processed
        }
        
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                count++;
                arr[j] = -1; // Mark repeated element as processed
            }
        }
        
        // Increment elements repeated twice
        if (count == 2) {
            for (int j = i; j < length; j++) {
                if (arr[j] == arr[i]) {
                    arr[j] += increment_amount;
                }
            }
        }
    }
}

int main() {
    int original_array[] = {1, 2, 3, 2, 4, 5, 4, 6};
    int length = sizeof(original_array) / sizeof(original_array[0]);
    int increment_amount = 10;

    increment_repeated_twice(original_array, length, increment_amount);

    printf("Incremented array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", original_array[i]);
    }
    
    return 0;
}
