#include "uefi.h"

EFI_SYSTEM_TABLE *gST;
EFI_BOOT_SERVICES *gBS;
EFI_GRAPHICS_OUTPUT_PROTOCOL *GOP;
EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *SFSP;
EFI_HANDLE IM;

void SwitchToResolution(unsigned int x, unsigned int y)
{
    unsigned long long sizeofInfo = 0;
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *info;
    for (unsigned int i = 0; i < GOP->Mode->MaxMode; i++) {
        GOP->QueryMode(GOP, i, &sizeofInfo, &info);

        if (info->HorizontalResolution == x && info->VerticalResolution == y) {
            GOP->SetMode(GOP, i);
        }
    }
}

void ClearScreen()
{
    gST->ConOut->ClearScreen(gST->ConOut);
}

void InitEfiEnvironment(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
    // global settings
    gST = SystemTable;
    gBS = SystemTable->BootServices;
    IM = ImageHandle;

    // protocol settings
    EFI_GUID gop_guid  = {0x9042a9de, 0x23dc, 0x4a38, {0x96, 0xfb, 0x7a, 0xde, 0xd0, 0x80, 0x51, 0x6a}};
    EFI_GUID sfsp_guid = {0x964e5b22, 0x6459, 0x11d2, {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}};
    gBS->SetWatchdogTimer(0, 0, 0, NULL);
    gBS->LocateProtocol(&gop_guid, NULL, (void **) &GOP);
    gBS->LocateProtocol(&sfsp_guid, NULL, (void **) &SFSP);

    // custom settings
    SwitchToResolution(1920, 1080);
    ClearScreen();
}