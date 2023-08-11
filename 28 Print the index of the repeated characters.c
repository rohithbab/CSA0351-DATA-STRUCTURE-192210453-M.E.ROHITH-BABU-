#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct HashMap {
    char key[MAX_SIZE];
    int value[MAX_SIZE][MAX_SIZE];
    int size;
};

void initialize(struct HashMap *map) {
    map->size = 0;
}

int findIndex(struct HashMap *map, char ch) {
    for (int i = 0; i < map->size; i++) {
        if (map->key[i] == ch) {
            return i;
        }
    }
    return -1;
}

void insert(struct HashMap *map, char ch, int index) {
    int mapIndex = findIndex(map, ch);
    if (mapIndex != -1) {
        int valueIndex = map->value[mapIndex][0];
        map->value[mapIndex][valueIndex] = index;
        map->value[mapIndex][0]++;
    } else {
        map->key[map->size] = ch;
        map->value[map->size][0] = 1;
        map->value[map->size][1] = index;
        map->size++;
    }
}

void printRepeatedCharacterIndices(struct HashMap *map) {
    printf("Indices of repeated characters:\n");
    for (int i = 0; i < map->size; i++) {
        if (map->value[i][0] > 1) {
            printf("%c:", map->key[i]);
            for (int j = 1; j <= map->value[i][0]; j++) {
                printf(" %d", map->value[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    char str[] = "programming";
    int length = strlen(str);

    struct HashMap indexMap;
    initialize(&indexMap);

    for (int i = 0; i < length; i++) {
        insert(&indexMap, str[i], i);
    }

    printRepeatedCharacterIndices(&indexMap);

    return 0;
}
