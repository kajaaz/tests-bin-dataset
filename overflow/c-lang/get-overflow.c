#include <stdio.h>
#include <string.h>

void vulnerable_function() {
    char buffer[128];
    printf("Enter some text:\n");
    gets(buffer);  // dangerous function, causes buffer overflow if input is longer than 127 characters
    printf("You entered: %s\n", buffer);
}

int main() {
    vulnerable_function();
    return 0;
}
