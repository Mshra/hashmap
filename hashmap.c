#include "fnv-1a.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int length;
} hmap;

int main(int argc, char *argv[]) {
  uint64_t hash = FNV_ONEA_64("bar");
  printf("0x%llx\n and %llu", hash, hash);
  return EXIT_SUCCESS;
}
