#include <stdio.h>
#include <string.h>

int main() {
    char haystack[] = "This is a sample haystack string.";
    char needle[] = "sample";

    char *result = strstr(haystack, needle);

    if (result) {
        printf("Needle found at index: %ld\n", result - haystack);
    } else {
        printf("Needle not found in haystack.\n");
    }

    return 0;
}

