#include "fnv-1a.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int hash = FNV_ONEA_32("hello\r");
  printf("0x%x", hash);
  return EXIT_SUCCESS;
}
