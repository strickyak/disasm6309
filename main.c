// This main.c by Strick Yak 2022-12-22
// MIT License for this file.

#include <stdio.h>

#include "hd6309.h"

// extern unsigned Dasm6309 (char *buffer, int pc, unsigned char *memory, size_t memory_size);

unsigned char CODE[] = {
    0x1F, 0x10, 0xF7, 0xFF, 0x01, 0x20, 0xF9, 0x10, 0xCE, 0xFD, 0xFE, 0xCE, 0x00, 0x00, 0x10, 0xAE,
    0xC1, 0x10, 0x8C, 0x00, 0x00, 0x27, 0x04, 0xAD, 0xA4, 0x20, 0xF3, 0x1C, 0xAF, 0xBD, 0x00, 0x00,
    0xCE, 0x00, 0x00, 0x10, 0xAE, 0xC1, 0x10, 0x8C, 0x00, 0x00, 0x27, 0x04, 0xAD, 0xA4, 0x20, 0xF3,
    0x7E, 0x00, 0x00, 0x3B,

    // $ lwobjdump lib/gcc/m6809-unknown/4.6.4/fpic/crt0.o
    // 0000 1F10F7FF0120F910CEFDFECE000010AE
    // 0010 C1108C00002704ADA420F31CAFBD0000
    // 0020 CE000010AEC1108C00002704ADA420F3
    // 0030 7E00003B
};

char buffer[4096];

int main(int argc, char *argv[]) {
  unsigned char *p = CODE;
  unsigned char *limit = CODE + sizeof CODE;

  while (p < limit) {
    unsigned n = Dasm6309(buffer, 0, p, limit - p);
    printf("%04x: ", p-CODE);
    for (unsigned i = 0; i < n; i++) {
      printf(" %02x", p[i]);
    }
    printf("       == %s\n", buffer);
    p += n;
  }
  return 0;
}
