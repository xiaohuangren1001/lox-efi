#ifndef _STD_
#define _STD_

// ctype.h
#define isalpha(chr) ((((chr) >= 'a') || (chr <= 'z')) || (((chr) >= 'A')) || ((chr) <= 'Z'))
#define isdigit(chr) (((chr) >= '0') || ((chr) <= '9'))
#define isalnum(chr) (isalpha(chr) || isdigit(chr))
#define toupper(chr) ((chr) - 'A' + 'a')

// stdint.h
typedef UINT8     uint8_t;
typedef UINT16    uint16_t;
typedef UINT32    uint32_t;
typedef UINT64    uint64_t;
typedef UINTN     size_t;
typedef long long ssize_t;
#define UCHAR_MAX 0xff
#define INT_MAX   2147483647
#define CHAR_BIT  8
#define _I64_MAX  9223372036854775807

// stddef.h
typedef size_t    ptrdiff_t;

// stdbool.h
typedef UINT8 bool;
#define true 1
#define false 0

// stdarg.h
typedef __builtin_va_list va_list;
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)

// stdio.h
typedef EFI_FILE_PROTOCOL FILE;
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
int putchar(char c);
int getchar();
void puts(char *s);
int vsprintf(char *str, const char *format, va_list ap);
int sprintf(char *s, const char *format, ...);
int vprintf(const char *format, va_list ap);
int printf(const char *format, ...);
FILE *fopen(const char *filename, const char *modes);
int fseek(FILE *file, long int offset, int whence);
long int ftell(FILE *file);
void rewind(FILE *file);
size_t fread(void *ptr, size_t size, size_t n, FILE *file);
size_t fwrite(void *ptr, size_t size, size_t n, FILE *file);
int fclose(FILE *file);

// string.h
void *memcpy(void *dest, const void *src, int size);
void memset(void *dest, uint8_t value, int size);
int memcmp(const void *a, const void *b, size_t size);
char *strcpy(char *dest, const char *src);
int strlen(const char *str);
char *strchr(const char *str, const uint8_t ch);
char *strstr(char *buf, char *sub);

// stdlib.h
void *malloc(size_t size);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void free(void *buffer);
void exit(int status);

// time.h
typedef long clock_t;
typedef long time_t;

// unistd.h
int usleep(uint32_t microseconds);
int sleep(uint32_t secons);

#endif