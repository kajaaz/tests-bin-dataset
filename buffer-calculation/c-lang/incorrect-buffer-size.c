#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerableFunction(char *input) {
    int bufSize = strlen(input);  // Incorrect buffer size calculation
    char *buffer = (char *)malloc(bufSize);  // Should be bufSize + 1 to account for the null terminator
    strcpy(buffer, input);  // Buffer overflow here due to incorrect buffer size calculation

    printf("%s\n", buffer);
    free(buffer);
}

int main() {
    char data[] = "hello, world";
    vulnerableFunction(data);
    return 0;
}
