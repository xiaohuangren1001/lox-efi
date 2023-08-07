#include "uefi.h"
#include "efi.h"

int str_to_int(const char *str)
{
    int x = 0, f = 1;
    char *p = (char *) str, ch = *p;
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        p++;
        ch = *p;
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        p++;
        ch = *p;
    }
    return x * f;
}

ssize_t getline(char *str, size_t n)
{
    if (str == NULL) str = (char *) malloc(n * sizeof(char));

    size_t i = 0;
    for (i = 0; i < n - 1; ) {
        str[i] = getchar();
        putchar(str[i]);
        if (str[i] == '\b') {
            i--;
            continue;
        } else if (str[i] == '\r') {
            putchar('\n');
            break;
        }
        i++;
    }
    str[i] = 0;
    return i;
}