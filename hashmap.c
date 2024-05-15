#include "fnv-1a.h"
#include <stdint.h>
#include <stdlib.h>

int get_index(char *key) { return (FNV_ONEA_64(key) % 16) - 1; }

void insert(char *hash_map[], char *key, int value) {
  *hash_map[get_index(key)] = value;
}

int main(int argc, char *argv[]) {
  char *hash_map[16];

  insert(hash_map, "bar", 42);
  insert(hash_map, "bazz", 36);
  insert(hash_map, "bob", 11);
  insert(hash_map, "buzz", 7);
  insert(hash_map, "foo", 10);
  insert(hash_map, "jane", 100);
  insert(hash_map, "x", 200);

  uint64_t hash = FNV_ONEA_64("bar");

  return EXIT_SUCCESS;
}
