#include <stdio.h>
#include <string.h>

void vulnerableFunction(char *src) {
    // Incorrectly calculating buffer size
    int bufSize = strlen(src) - 1;
    char dst[bufSize];
    strncpy(dst, src, strlen(src));  // This line could lead to a buffer overflow

    printf("%s\n", dst);
}

int main() {
    char data[] = "hello, world";
    vulnerableFunction(data);
    return 0;
}
