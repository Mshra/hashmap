#include <stdint.h>

/*
 * This C file implements the Fowler-Noll-Vo (FNV) hash algorithm variant 1a,
 * which is a non-cryptographic hash function. It iterates through each
 * character of the input string, XORing the hash with the character's value and
 * then multiplying by a prime number. This process is repeated for each
 * character in the string.
 */

const uint32_t FNV_32_OFFSET = 0x811c9dc5; // 2166136261
const uint32_t FNV_32_PRIME = 0x1000193;   // 16777619

const uint64_t FNV_64_OFFSET = 0xcbf29ce484222325; // 14695981039346656037
const uint64_t FNV_64_PRIME = 0x100000001b3;       // 1099511628211U

/**
 * @brief Calculate the FNV-1a 32-bit hash of a given string.
 *
 * @param string The input string for which the hash is to be calculated.
 * @return The 32-bit hash value of the input string.
 */
static uint32_t FNV_ONEA_32(char *string) {
  uint32_t hash = FNV_32_OFFSET; // Initialize the hash with FNV offset basis.

  // Iterate through each character of the input string.
  while (*string) {
    int c = *string;      // Get the ASCII value of the current character.
    hash ^= c;            // XOR the hash with the ASCII value of the character.
    hash *= FNV_32_PRIME; // Multiply the hash by the FNV prime constant.
    string = string + 1;  // Move to the next character in the string.
  }

  return hash; // Return the final hash value.
}

/**
 * @brief Calculate the FNV-1a 64-bit hash of a given string.
 *
 * @param string The input string for which the hash is to be calculated.
 * @return The 64-bit hash value of the input string.
 */
static uint64_t FNV_ONEA_64(char *string) {
  uint64_t hash = FNV_64_OFFSET; // Initialize the hash with FNV offset basis.

  // Iterate through each character of the input string.
  while (*string) {
    int c = *string;      // Get the ASCII value of the current character.
    hash ^= c;            // XOR the hash with the ASCII value of the character.
    hash *= FNV_64_PRIME; // Multiply the hash by the FNV prime constant.
    string = string + 1;  // Move to the next character in the string.
  }

  return hash; // Return the final 64-bit hash value.
}
