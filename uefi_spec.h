#ifndef _UEFI_SPEC_
#define _UEFI_SPEC_

typedef struct {
    // EFI_TABLE_HEADER
    char _pad[24];
    // Task Priority Services
    UINTN _pad2[2];
    // Memory Services
    EFI_STATUS (*AllocatePages)(EFI_ALLOCATE_TYPE Type, EFI_MEMORY_TYPE MemoryType, UINTN Pages, EFI_PHYSICAL_ADDRESS *Memory);
    EFI_STATUS (*FreePages)(EFI_PHYSICAL_ADDRESS Memory, UINTN Pages);
    EFI_STATUS (*GetMemoryMap)(UINTN *MemoryMapSize, EFI_MEMORY_DESCRIPTOR *MemoryMap, UINTN *MapKey, UINTN *DescriptorSize, UINT32 *DescriptorVersion);
    EFI_STATUS (*AllocatePool)(EFI_MEMORY_TYPE PoolType, UINTN Size, VOID **Buffer);
    EFI_STATUS (*FreePool)(VOID *Buffer);
    // Event & Timer Services
    UINTN _pad3[2];
    EFI_STATUS (*WaitForEvent)(UINTN NumberOfEvents, EFI_EVENT *Event, UINTN *Index);
    UINTN _pad3_2[3];
    // Protocol Handler Services
    UINTN _pad4[9];
    // Image Services
    UINTN _pad5[2];
    EFI_STATUS (*Exit)(EFI_HANDLE ImageHandle, EFI_STATUS ExitStatus, UINTN ExitDataSize, CHAR16 *ExitData);
    UINTN _pad5_2;
    EFI_STATUS (*ExitBootServices)(EFI_HANDLE ImageHandle, UINTN MapKey);
    // Miscellaneous Services
    UINTN _pad6;
    EFI_STATUS (*Stall)(UINTN microseconds);
    EFI_STATUS (*SetWatchdogTimer)(UINTN Timeout, UINT64 WatchdogCode, UINTN DataSize, UINT16 *WatchDogData);
    // DriverSupport Services
    UINTN _pad7[2];
    // Open & Close Protocol Services
    EFI_STATUS (*OpenProtocol)(EFI_HANDLE Handle, EFI_GUID *Protocol, VOID **Interface, EFI_HANDLE AgentHandle, EFI_HANDLE ControllerHandle, UINT32 Attributes);
    UINTN _pad8[2];
    // Library Services
    UINTN _pad9[2];
    EFI_STATUS (*LocateProtocol)(EFI_GUID *Protocol, VOID *Registeration, VOID **Interface);
    UINTN _pad10[2];
    // 32-bit CRC Services
    UINTN _pad11;
    // Miscellaneous Services
    UINTN _pad12[3];
} EFI_BOOT_SERVICES;

typedef struct {
    char _pad[44];
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;

    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;

    EFI_HANDLE ConsoleErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
    EFI_HANDLE *RuntimeServices;
    EFI_BOOT_SERVICES *BootServices;
} EFI_SYSTEM_TABLE;

#endif