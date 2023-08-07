#include "uefi.h"
#include "lox.h"

EFI_STATUS efi_main(EFI_HANDLE ImageHandle UNUSED, EFI_SYSTEM_TABLE *SystemTable)
{
    InitEfiEnvironment(ImageHandle, SystemTable);

    printf("Lox (build on Aug 3 2023, 22:14:16) [UEFI (x86_64)] on UEFI Firmware\n");
    printf("Type `print changes();` to see what is changed in this version,\nor type `print credits();` or `print copyright();` to see more information\n");

    initVM();

    repl();

    freeVM();
    while (1);
}