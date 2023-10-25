#include <stdio.h>
#include <string.h>

void vulnerableFunction(char *userInput) {
    char buffer[10];
    for (int i = 0; i < strlen(userInput); i++) {
        buffer[i] = userInput[i];  // This line causes a buffer overflow when userInput is longer than 10 characters
    }
    printf("%s\n", buffer);
}

int main() {
    char input[256];
    printf("Enter input:\n");
    scanf("%255s", input);  // Limiting input to 255 characters to prevent overflow here, but not in vulnerableFunction
    vulnerableFunction(input);
    // This line demonstrates the issue by printing the address of buffer
    printf("Address of input: %p\n", (void*)&input);
    return 0;
}
