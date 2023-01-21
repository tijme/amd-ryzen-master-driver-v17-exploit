#pragma once

#pragma pack(push,1)
typedef struct _AMD_PACKET
{
    int64_t address;            // Address to read from or write to
    int32_t size;               // Amount to read or write
    #ifndef BOF
        uint8_t value[0x1000];  // The value to read from or write to
    #else
        uint8_t value[0x900];   // The value to read from or write to (CobaltStrike has a stack limitation)
    #endif
} AMD_PACKET, * PAMD_PACKET;
#pragma pack(pop)

typedef struct _SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX {
	PVOID Object;
	ULONG_PTR UniqueProcessId;
	ULONG_PTR HandleValue;
	ULONG GrantedAccess;
	USHORT CreatorBackTraceIndex;
	USHORT ObjectTypeIndex;
	ULONG HandleAttributes;
	ULONG Reserved;
} SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX, * PSYSTEM_HANDLE_TABLE_ENTRY_INFO_EX;

typedef struct _SYSTEM_HANDLE_INFORMATION_EX {
	ULONG_PTR NumberOfHandles;
	ULONG_PTR Reserved;
	SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX Handles[1];
} SYSTEM_HANDLE_INFORMATION_EX, * PSYSTEM_HANDLE_INFORMATION_EX;

typedef struct _RTL_PROCESS_MODULE_INFORMATION {
    HANDLE Section;
    PVOID MappedBase;
    PVOID ImageBase;
    ULONG ImageSize;
    ULONG Flags;
    USHORT LoadOrderIndex;
    USHORT InitOrderIndex;
    USHORT LoadCount;
    USHORT OffsetToFileName;
    UCHAR FullPathName[256];
} RTL_PROCESS_MODULE_INFORMATION, *PRTL_PROCESS_MODULE_INFORMATION;

typedef struct _RTL_PROCESS_MODULES {
    ULONG NumberOfModules;
    RTL_PROCESS_MODULE_INFORMATION Modules[1];
} RTL_PROCESS_MODULES, *PRTL_PROCESS_MODULES;

typedef struct _POOL_HEADER
{
    union
    {
        struct
        {
            USHORT PreviousSize:8;                                          //0x0
            USHORT PoolIndex:8;                                             //0x0
            USHORT BlockSize:8;                                             //0x2
            USHORT PoolType:8;                                              //0x2
        };
        ULONG Ulong1;                                                       //0x0
    };
    ULONG PoolTag;                                                          //0x4
    union
    {
        struct _EPROCESS* ProcessBilled;                                    //0x8
        struct
        {
            USHORT AllocatorBackTraceIndex;                                 //0x8
            USHORT PoolTagHash;                                             //0xa
        };
    };
} POOL_HEADER, *PPOOL_HEADER;

typedef struct _RTL_BALANCED_NODE
{
    union
    {
        struct _RTL_BALANCED_NODE* Children[2];                             //0x0
        struct
        {
            struct _RTL_BALANCED_NODE* Left;                                //0x0
            struct _RTL_BALANCED_NODE* Right;                               //0x8
        };
    };
    union
    {
        struct
        {
            UCHAR Red:1;                                                    //0x10
            UCHAR Balance:2;                                                //0x10
        };
        ULONGLONG ParentValue;                                              //0x10
    };
} RTL_BALANCED_NODE, *PRTL_BALANCED_NODE;

typedef struct _EX_FAST_REF
{
     union
     {
          PVOID Object;
          ULONG RefCnt: 3;
          ULONG Value;
     };
} EX_FAST_REF, *PEX_FAST_REF;
