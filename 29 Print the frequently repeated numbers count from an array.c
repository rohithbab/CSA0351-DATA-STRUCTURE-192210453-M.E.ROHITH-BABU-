#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct HashMap {
    int key[MAX_SIZE];
    int value[MAX_SIZE];
    int size;
};

void initialize(struct HashMap *map) {
    map->size = 0;
}

int findIndex(struct HashMap *map, int num) {
    for (int i = 0; i < map->size; i++) {
        if (map->key[i] == num) {
            return i;
        }
    }
    return -1;
}

void insert(struct HashMap *map, int num) {
    int index = findIndex(map, num);
    if (index != -1) {
        map->value[index]++;
    } else {
        map->key[map->size] = num;
        map->value[map->size] = 1;
        map->size++;
    }
}

void printFrequentNumbers(struct HashMap *map, int threshold) {
    printf("Frequently repeated numbers (count >= %d):\n", threshold);
    for (int i = 0; i < map->size; i++) {
        if (map->value[i] >= threshold) {
            printf("%d (Count: %d)\n", map->key[i], map->value[i]);
        }
    }
}

int main() {
    int arr[] = {4, 2, 8, 4, 5, 2, 6, 7, 8, 8, 7, 4, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int threshold = 3; // Minimum occurrence count to be considered frequent

    struct HashMap frequencyMap;
    initialize(&frequencyMap);

    for (int i = 0; i < size; i++) {
        insert(&frequencyMap, arr[i]);
    }

    printFrequentNumbers(&frequencyMap, threshold);

    return 0;
}
