# lox-efi
Porting lox to UEFI Firmware

---
## What do you need:

* gcc compiler (from MinGW-w64 project)
* [qemu](https://qemu.org)

---
## How to run:
**Run in QEMU:**
* Create a directory called `esp`. Then, create `EFI` directory under `esp`, and create a `BOOT` directory under `esp/EFI`.
* Simply type `make` to launch it in qemu.

**Boot to real computer:**
* Grab an useless portable disk, then format it into FAT32 file system.
* Create a directory called `EFI` in disk. Then, create a `BOOT` directory under `EFI`.
* Use `make compile` to compile the EFI file (default to `main.efi`), then copy it to the `BOOT` directory we just created.
* Rename `main.efi` to `BOOTX64.EFI`.
* In the `UEFI Firmware Settings` page, drag the portable disk we just used to the first item of the page `boot options`.

If you have done everything correct, you can see a Lox prompt in the QEMU window or on the screen of the computer.
