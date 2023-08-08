#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
	int i;
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    bool isValid = true;

    for (i = 0; i < strlen(input); i++) {
        if (!((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9'))) {
            isValid = false;
            break;
        }
    }

    if (isValid) {
        printf("The string is valid.\n");
    } else {
        printf("The string is not valid.\n");
    }

    return 0;
}

