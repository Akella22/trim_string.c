#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Функція для видалення початкових і кінцевих пробілів
void trim(char* str) {
    int start = 0;
    int end = strlen(str) - 1;

    // Знайти перший символ, який не є пробілом
    while (str[start] == ' ' && str[start] != '\0') {
        start++;
    }

    // Знайти останній символ, який не є пробілом
    while (end >= start && str[end] == ' ') {
        end--;
    }

    // Зсунути всі символи на початок
    int i = 0;
    while (start <= end) {
        str[i++] = str[start++];
    }
    str[i] = '\0'; // Завершити рядок 
}

int main() {
    char input[256];

    // Введення строки від користувача
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Видалення символу нового рядка (\n), якщо він присутній
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Видалення початкових і кінцевих пробілів
    trim(input);

    // Виведення результату
    printf("Trimmed string: '%s'\n", input);

    return 0;
}
