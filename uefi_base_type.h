#ifndef _UEFI_BASE_TYPE_
#define _UEFI_BASE_TYPE_

typedef unsigned long long UINT64;
typedef unsigned int       UINT32;
typedef unsigned short     UINT16;
typedef UINT16             CHAR16;
typedef unsigned char      UINT8;
typedef char               CHAR8;
typedef UINT64             UINTN;
typedef UINTN              EFI_STATUS;
typedef UINTN              EFI_PHYSICAL_ADDRESS;
typedef UINTN              EFI_VIRTUAL_ADDRESS;
typedef void               VOID;
typedef VOID*              EFI_HANDLE;
typedef VOID*              EFI_EVENT;

#define NULL               ((VOID *) 0)

#define UNUSED             __attribute__((unused))

#define EFI_FILE_MODE_READ   0x0000000000000001
#define EFI_FILE_MODE_WRITE  0x0000000000000002
#define EFI_FILE_MODE_CREATE 0x8000000000000000

typedef enum {
    AllocateAnyPages,
    AllocateMaxAddress,
    AllocateAddress,
    MaxAllocateType
} EFI_ALLOCATE_TYPE;

typedef enum {
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiRuntimeServicesCode,
    EfiRuntimeServicesData,
    EfiConventionalMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMappedIO,
    EfiMemoryMappedIOPortSpace,
    EfiPalCode,
    EfiMaxMemoryType
} EFI_MEMORY_TYPE;

typedef struct {
    UINT32 Type;
    EFI_PHYSICAL_ADDRESS PhysicalStart;
    EFI_VIRTUAL_ADDRESS VirtualStart;
    UINT64 NumberOfPages;
    UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

typedef struct {
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8 Data4[8];
} EFI_GUID;

typedef struct {
    UINT16      Year;       /* 1998 - 2XXX */
    UINT8      Month;      /* 1 - 12 */
    UINT8       Day;        /* 1 - 31 */
    UINT8       Hour;       /* 0 - 23 */
    UINT8       Minute;     /* 0 - 59 */
    UINT8       Second;     /* 0 - 59 */
    UINT8       Pad1;
    UINT32      Nanosecond; /* 0 - 999,999,999 */
    short       TimeZone;   /* -1440 to 1440 or 2047 */
    UINT8       Daylight;
    UINT8       Pad2;
} EFI_TIME;

typedef struct {
    CHAR16 ScanCode, UnicodeChar;
} EFI_INPUT_KEY;

#define EFI_ERROR_MASK 0x8000000000000000
#define EFIERR(a) (EFI_ERROR_MASK | a)
#define EFI_ERROR(status) (((long long) status) < 0)

#define EFI_SUCCESS                     0
#define EFI_LOAD_ERROR                  EFIERR(1)
#define EFI_INVALID_PARAMETER           EFIERR(2)
#define EFI_UNSUPPORTED                 EFIERR(3)
#define EFI_BAD_BUFFER_SIZE             EFIERR(4)
#define EFI_BUFFER_TOO_SMALL            EFIERR(5)
#define EFI_NOT_READY                   EFIERR(6)
#define EFI_DEVICE_ERROR                EFIERR(7)
#define EFI_WRITE_PROTECTED             EFIERR(8)
#define EFI_OUT_OF_RESOURCES            EFIERR(9)
#define EFI_VOLUME_CORRUPTED            EFIERR(10)
#define EFI_VOLUME_FULL                 EFIERR(11)
#define EFI_NO_MEDIA                    EFIERR(12)
#define EFI_MEDIA_CHANGED               EFIERR(13)
#define EFI_NOT_FOUND                   EFIERR(14)
#define EFI_ACCESS_DENIED               EFIERR(15)
#define EFI_NO_RESPONSE                 EFIERR(16)
#define EFI_NO_MAPPING                  EFIERR(17)
#define EFI_TIMEOUT                     EFIERR(18)
#define EFI_NOT_STARTED                 EFIERR(19)
#define EFI_ALREADY_STARTED             EFIERR(20)
#define EFI_ABORTED                     EFIERR(21)
#define EFI_ICMP_ERROR                  EFIERR(22)
#define EFI_TFTP_ERROR                  EFIERR(23)
#define EFI_PROTOCOL_ERROR              EFIERR(24)
#define EFI_INCOMPATIBLE_VERSION        EFIERR(25)
#define EFI_SECURITY_VIOLATION          EFIERR(26)
#define EFI_CRC_ERROR                   EFIERR(27)
#define EFI_END_OF_MEDIA                EFIERR(28)
#define EFI_END_OF_FILE                 EFIERR(31)
#define EFI_INVALID_LANGUAGE            EFIERR(32)
#define EFI_COMPROMISED_DATA            EFIERR(33)

#endif