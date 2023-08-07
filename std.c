#include "uefi.h"

int putchar(char c)
{
    if (c == '\n') putchar('\r');
    UINT16 String[2] = {c, 0};
    gST->ConOut->OutputString(gST->ConOut, String);
    return c;
}

int getchar()
{
    UINTN index;
    gBS->WaitForEvent(1, &gST->ConIn->WaitForKey, &index);
    EFI_INPUT_KEY key = {0, 0};
    EFI_STATUS status = gST->ConIn->ReadKeyStroke(gST->ConIn, &key);
    return EFI_ERROR(status) ? -1 : key.UnicodeChar & 0xff;
}

void puts(char *s)
{
    for (; *s; s++) putchar(*s);
}

void *memcpy(void *dest, const void *src, int size)
{
    UINT8 *dst = (UINT8 *) dest;
    UINT8 *source = (UINT8 *) src;
    while (size-- > 0) *dst++ = *source++;
    return dest;
}

void memset(void *dest, UINT8 value, int size)
{
    UINT8 *dst = (UINT8 *) dest;
    while (size-- > 0) *dst++ = value;
}

int memcmp(const void *a, const void *b, size_t size)
{
    const UINT8 *a_ = a;
    const UINT8 *b_ = b;

    while (size-- > 0) {
        if (*a_ != *b_) return *a_ > *b_ ? 1 : -1;
        a_++;
        b_++;
    }

    return 0;
}

char *strcpy(char *dest, const char *src)
{
    char *r = dest;
    while ((*dest++ = *src++));
    return r;
}

int strlen(const char *str)
{
    const char *p = str;
    while (*p++);
    return p - str - 1;
}

char *strchr(const char *str, const uint8_t ch)
{
    while (*str) {
        if (*str == ch) return (char *) str;
        str++;
    }
    return NULL;
}

char *strstr(char *buf, char *sub)
{
    if (!*sub) return (char *) buf;

    char *bp, *sp;
    while (*buf)
    {
        bp = buf;
        sp = sub;
        do {
            if (!*sp) return buf;
        } while ((*bp++ == *sp++));
        buf++;
    }
    return 0;
}

void itoa(UINT32 value, char **buf_ptr_addr, UINT8 base)
{
    UINT32 m = value % base;
    UINT32 i = value / base;
    if (i) itoa(i, buf_ptr_addr, base);

    if (m < 10) {
        *((*buf_ptr_addr)++) = m + '0';
    } else {
        *((*buf_ptr_addr)++) = m - 10 + 'A';
    }
}

int vsprintf(char *str, const char *format, va_list ap)
{
    char *buf_ptr = str;
    const char *index_ptr = format;
    char index_char = *index_ptr;
    int arg_int;
    char *arg_str;

    while (index_char) {
        if (index_char != '%') {
            *(buf_ptr++) = index_char;
            index_char = *(++index_ptr);
            continue;
        }
        index_char = *(++index_ptr);
        switch (index_char) {
            case 'x':
                arg_int = va_arg(ap, int);
                itoa(arg_int, &buf_ptr, 16);
                index_char = *(++index_ptr);
                break;

            case 'c':
                *(buf_ptr++) = va_arg(ap, int);
                index_char = *(++index_ptr);
                break;

            case 'd':
                arg_int = va_arg(ap, int);
                if (arg_int < 0) {
                    arg_int = -arg_int;
                    *buf_ptr++ = '-';
                }
                itoa(arg_int, &buf_ptr, 10);
                index_char = *(++index_ptr);
                break;
            case 's':
                arg_str = va_arg(ap, char*);
                strcpy(buf_ptr, arg_str);
                buf_ptr += strlen(arg_str);
                index_char = *(++index_ptr);
                break;
        }
    }
    
    return strlen(str);
}

int sprintf(char *s, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int i = vsprintf(s, format, args);
    va_end(args);
    return i;
}

int vprintf(const char *format, va_list args)
{
    char buf[1024] = {0};
    int ret = vsprintf(buf, format, args);
    puts(buf);
    return ret;
}

int printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    char buf[1024] = {0};
    int ret = vsprintf(buf, format, args);
    va_end(args);
    puts(buf);
    return ret;
}

void *malloc(size_t size)
{
    void *ret = NULL;
    EFI_STATUS status;
    status = gBS->AllocatePool(EfiLoaderData, size, &ret);
    if (EFI_ERROR(status) || !ret) ret = NULL;
    return ret;
}

void *calloc(size_t nmemb, size_t size)
{
    void *ret = malloc(nmemb * size);
    if (ret) memset(ret, 0, nmemb * size);
    return ret;
}

void *realloc(void *ptr, size_t  size)
{
    void *ret = NULL;
    if (!ptr) return malloc(size);
    if (!size) {
        free(ptr);
        return NULL;
    }
    ret = malloc(size);
    if (!ret) return NULL;
    memcpy(ret, ptr, size);
    free(ptr);
    return ret;
}

void free(void *buffer)
{
    gBS->FreePool(buffer);
}

void exit(int status)
{
    gBS->Exit(IM, !status ? 0 : (status < 0 ? EFIERR(-status) : EFIERR(status)), 0, NULL);
}

int usleep(uint32_t microseconds)
{
    gBS->Stall(microseconds);
    return 0;
}

int sleep(uint32_t seconds)
{
    gBS->Stall(seconds * 1000000);
    return 0;
}

void ___chkstk_ms() {}