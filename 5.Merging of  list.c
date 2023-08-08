#include <stdio.h>

int main() {
    int i,list1[100], list2[100], mergedList[200];
    int size1, size2;

    printf("Enter the size of the first list: ");
    scanf("%d", &size1);

    printf("Enter elements of the first list:\n");
    for (i = 0; i < size1; i++) {
        scanf("%d", &list1[i]);
        mergedList[i] = list1[i];
    }

    printf("Enter the size of the second list: ");
    scanf("%d", &size2);

    printf("Enter elements of the second list:\n");
    for (i = 0; i < size2; i++) {
        scanf("%d", &list2[i]);
        mergedList[size1 + i] = list2[i];
    }

    int mergedSize = size1 + size2;

    printf("Merged list:\n");
    for (i = 0; i < mergedSize; i++) {
        printf("%d ", mergedList[i]);
    }

    return 0;
}

