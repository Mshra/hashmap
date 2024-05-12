/* implementation of FNV-1A HASH */

#include <stdint.h>

const uint32_t FNV_32_OFFSET = 0x811c9dc5; // 2166136261
const uint32_t FNV_32_PRIME = 0x1000193;   // 16777619

const uint64_t FNV_64_OFFSET = 0xcbf29ce484222325; // 14695981039346656037
const uint64_t FNV_64_PRIME = 0x100000001b3;       // 1099511628211U

static uint32_t FNV_ONEA_32(char *string) {
  uint8_t byte_of_data = 8;
  uint32_t hash = FNV_32_OFFSET;

  while (*string) {
    int c = *string;
    hash ^= c;
    hash *= FNV_32_PRIME;
    string = string + 1;
  }
  return hash;
}

static uint64_t FNV_ONEA_64(char *string) {
  uint8_t byte_of_data = 8;
  uint64_t hash = FNV_64_OFFSET;

  while (*string) {
    int c = *string;
    hash ^= c;
    hash *= FNV_64_PRIME;
    string = string + 1;
  }
  return hash;
}
