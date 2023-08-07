ENTRYPOINT = efi_main

OPTIONS = -nostdlib -nostdinc -fno-builtin -Wl,--subsystem,10 -e $(ENTRYPOINT) -I .
SOURCES = main.c efi.c lib.c std.c lox/chunk.c lox/compiler.c lox/debug.c lox/main.c lox/memory.c lox/object.c lox/scanner.c lox/table.c lox/value.c lox/vm.c

TARGET = main.efi

default : compile launchqemu

compile :
	@gcc $(OPTIONS) $(SOURCES) -o $(TARGET)

launchqemu :
	@cmd /c copy main.efi esp\EFI\BOOT\BOOTX64.EFI
	@qemu-system-x86_64 -bios OVMF.fd -drive file=fat:rw:esp,index=0,format=vvfat