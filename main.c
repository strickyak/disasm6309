// This main.c by Strick Yak 2022-12-22
// MIT License for this file.

#include <stdio.h>
#include <assert.h>
#include <unistd.h>

#include "hd6309.h"

char Binary[4096];
char Buffer[4096];
char OpBytes[8];

int main(int argc, char *argv[]) {
  int cc = read(0, Binary, sizeof Binary);
  assert(cc > 0);

  int i = 0;
  while (i < cc) {
    // unsigned Dasm6309 (char *buffer, int pc, unsigned char *memory, size_t memory_size);
    unsigned n = Dasm6309(Buffer, i, Binary, cc);
    for (unsigned j = 0; j < n; j++) {
      sprintf(OpBytes+j+j, "%02x", (unsigned char)Binary[i+j]);
    }
    printf("%04x:  %-12s  %s\n", i, OpBytes, Buffer);
    i += n;
  }
  return 0;
}
