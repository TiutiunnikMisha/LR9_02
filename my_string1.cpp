#include "my_string1.h"
#include <cstring>
#include <cstdio>

void my_replace(char* str, int pos, int len, const char* substr) {
    size_t original_len = strlen(str);
    size_t substr_len = strlen(substr);

    if (pos < 0 || static_cast<size_t>(pos) > original_len) return;

    size_t tail_start = pos + len;
    if (tail_start > original_len) tail_start = original_len;

    char temp[256];
    strcpy_s(temp, sizeof(temp), str + tail_start); // безпечне копіювання

    // перевірка на переповнення
    if (substr_len + strlen(temp) + pos >= 256) return;

    str[pos] = '\0'; // обрізаємо рядок до позиції
    strcat_s(str, 256, substr); // додаємо підрядок
    strcat_s(str, 256, temp);   // додаємо кінець рядка
}
