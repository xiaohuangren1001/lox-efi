#ifndef _EFI_
#define _EFI_

// efi.c
void SwitchToResolution(unsigned int x, unsigned int y);
void ClearScreen();
void InitEfiEnvironment(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable);

// lib.c
void draw_pixel(int x, int y, int rgb);
int str_to_int(const char *str);
ssize_t getline(char *str, size_t n);

#endif