#include <stdio.h>
#include <string.h>

void inverterString(char str[]) {
    int size = 0;
    
    while (str[size] != '\0') {
        size++;
    }

    for (int i = 0; i < size / 2; i++) {
        char tmp = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = tmp;
    }
}

int main() {
    char str[100];

    printf("Informe uma string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    inverterString(str);

    printf("String invertida: %s\n", str);

    return 0;
}
