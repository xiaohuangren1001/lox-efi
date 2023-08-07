#ifndef _UEFI_PROTOCOL_
#define _UEFI_PROTOCOL_

typedef struct {
    UINT64                  Size;
    UINT64                  FileSize;
    UINT64                  PhysicalSize;
    EFI_TIME                CreateTime;
    EFI_TIME                LastAccessTime;
    EFI_TIME                ModificationTime;
    UINT64                  Attribute;
    CHAR16                  FileName[262];
} EFI_FILE_INFO;

typedef struct EFI_FILE_PROTOCOL {
    UINT64 Revision;
    EFI_STATUS (*Open)(struct EFI_FILE_PROTOCOL *This, struct EFI_FILE_PROTOCOL **NewHandle, CHAR16 *FileName, UINT64 OpenMode, UINT64 Attributes);
    EFI_STATUS (*Close)(struct EFI_FILE_PROTOCOL *This);
    EFI_STATUS (*Delete)(struct EFI_FILE_PROTOCOL *This);
    EFI_STATUS (*Read)(struct EFI_FILE_PROTOCOL *This, UINTN *BufferSize, VOID *Buffer);
    EFI_STATUS (*Write)(struct EFI_FILE_PROTOCOL *This, UINTN *BufferSize, VOID *Buffer);
    EFI_STATUS (*GetPosition)(struct EFI_FILE_PROTOCOL *This, UINT64 *Position);
    EFI_STATUS (*SetPosition)(struct EFI_FILE_PROTOCOL *This, UINT64 Position);
    EFI_STATUS (*GetInfo)(struct EFI_FILE_PROTOCOL *This, EFI_GUID *InformationType, UINTN *BufferSize, VOID *Buffer);
    EFI_STATUS (*SetInfo)(struct EFI_FILE_PROTOCOL *This, EFI_GUID *InformationType, UINTN BufferSize, VOID *Buffer);
    EFI_STATUS (*Flush)(struct EFI_FILE_PROTOCOL *This);
} EFI_FILE_PROTOCOL;

typedef struct EFI_SIMPLE_FILE_SYSTEM_PROTOCOL {
    UINTN Revision;
    EFI_STATUS (*OpenVolume)(struct EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *This, EFI_FILE_PROTOCOL **Root);
} EFI_SIMPLE_FILE_SYSTEM_PROTOCOL;

typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
    UINTN _pad;
    EFI_STATUS (*ReadKeyStroke)(struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This, EFI_INPUT_KEY *Key);
    EFI_EVENT WaitForKey;
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    UINTN _buf;
    EFI_STATUS (*OutputString)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, CHAR16 *String);
    UINTN _buf2[4];
    EFI_STATUS (*ClearScreen)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This);
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef struct {
    UINT8 Blue;
    UINT8 Green;
    UINT8 Red;
    UINT8 Reserved;
} EFI_GRAPHICS_OUTPUT_BLT_PIXEL;

typedef enum {
    PixelRedGreenBlueReserved8BitPerColor,
    PixelBlueGreenRedReserved8BitPerColor,
    PixelBitMask,
    PixelBltOnly,
    PixelFormatMax
} EFI_GRAPHICS_PIXEL_FORMAT;

typedef struct {
    UINT32 Version;
    UINT32 HorizontalResolution;
    UINT32 VerticalResolution;
    EFI_GRAPHICS_PIXEL_FORMAT PixelFormat;
} EFI_GRAPHICS_OUTPUT_MODE_INFORMATION;

typedef struct {
    UINT32 MaxMode;
    UINT32 Mode;
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *Info;
    UINTN SizeOfInfo;
    EFI_PHYSICAL_ADDRESS FrameBufferBase;
    UINTN FrameBufferSize;
} EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE;

typedef struct EFI_GRAPHICS_OUTPUT_PROTOCOL {
    EFI_STATUS (*QueryMode)(struct EFI_GRAPHICS_OUTPUT_PROTOCOL *This, UINT32 ModeNumber, UINTN *SizeOfInfo, EFI_GRAPHICS_OUTPUT_MODE_INFORMATION **Info);
    EFI_STATUS (*SetMode)(struct EFI_GRAPHICS_OUTPUT_PROTOCOL *This, UINT32 ModeNumber);
    UINTN _pad;
    EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE *Mode;
} EFI_GRAPHICS_OUTPUT_PROTOCOL;

#endif