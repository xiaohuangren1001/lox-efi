#include "uefi.h"

//< Scanning on Demand main-includes
#include "common.h"
//> main-include-chunk
#include "chunk.h"
//< main-include-chunk
//> main-include-debug
#include "debug.h"
//< main-include-debug
//> A Virtual Machine main-include-vm
#include "vm.h"
//< A Virtual Machine main-include-vm
//> Scanning on Demand repl

char line[1024];

void repl() {
  for (;;) {
    printf("> ");

    if (!getline(line, sizeof(line))) {
      printf("\n");
      break;
    }

    interpret(line);
  }
}
//< Scanning on Demand repl
