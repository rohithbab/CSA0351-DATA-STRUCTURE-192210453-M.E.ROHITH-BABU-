#include <stdio.h>

int main() {
    int i,regNumbers[100];
    int numStudents, searchRegNo;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    printf("Enter the registration numbers:\n");
    for (i = 0; i < numStudents; i++) {
        scanf("%d", &regNumbers[i]);
    }

    printf("Enter the registration number to search for: ");
    scanf("%d", &searchRegNo);

    int foundIndex = -1;

    for (i = 0; i < numStudents; i++) {
        if (regNumbers[i] == searchRegNo) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("Registration number %d found at index %d.\n", searchRegNo, foundIndex);
    } else {
        printf("Registration number %d not found.\n", searchRegNo);
    }

    return 0;
}

