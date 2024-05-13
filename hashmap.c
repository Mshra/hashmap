#include "fnv-1a.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int length; // length of the array of h_map
  int *arr[]; // array of key where each key(pointer) points to value.
} H_Map;

void insert(H_Map *map, char *key) {}

int main(int argc, char *argv[]) {
  int length = 16;
  int arr[length];

  H_Map *map;
  insert(map, "bar");

  uint64_t hash = FNV_ONEA_64("bar");

  printf("0x%llx\n and %llu", hash, hash % 16);
  return EXIT_SUCCESS;
}
