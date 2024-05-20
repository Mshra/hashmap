#include "fnv-1a.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int get_index(char *key) { return (FNV_ONEA_64(key) % 16) - 1; }

void insert(char *hash_map[], char *key, int value) {
  *hash_map[get_index(key)] = value;
}

/*
 * start with an array of 2**0 i.e. 1 element.
 * track the the length of the hashmap
 * if the index of key turns out to be more than the length of the array
 * copy the elements of the array and create a new array with the length of
 * 2**(n+1)
 *
 */

// This struct represents an item with a key-value pair for hash-map.
typedef struct {
  char *key;    // A pointer to a character string, representing the key
  size_t value; // An unsigned integer type, representing the value associated
                // with the key
} Item;

// This struct represents a hash-map
typedef struct {
  int length;    // The length of the array, indicating the number of items
  Item *array[]; // A flexible array member for storing pointers to Items
                 // The size of this array is determined at runtime
} H_Map;

H_Map *create_map() {
  H_Map *map = (H_Map *)malloc(sizeof(H_Map));
  map->length = 1;
  map->array[0] = NULL;
  return map;
}

int main(int argc, char *argv[]) {

  H_Map *map = create_map();
  printf("%d\n", map->array[0]);

  if (NULL == 0) {
    printf("you are insane\n");
  }

  // insert(hash_map, "bar", 42);
  printf("%d\n", get_index("bar"));
  printf("%d\n", get_index("bazz"));
  printf("%d\n", get_index("bob"));
  printf("%d\n", get_index("buzz"));
  // insert(hash_map, "bazz", 36);
  // insert(hash_map, "bob", 11);
  // insert(hash_map, "buzz", 7);
  // insert(hash_map, "foo", 10);
  // insert(hash_map, "jane", 100);
  // insert(hash_map, "x", 200);

  free(map);
  return EXIT_SUCCESS;
}
