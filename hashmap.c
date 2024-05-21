#include "fnv-1a.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int get_index(char *key) { return (FNV_ONEA_64(key) % 16); }
//
// void insert(char *hash_map[], char *key, int value) {
//   *hash_map[get_index(key)] = value;
// }

// Item is a <key-value> pair of a hash_map
typedef struct {
  char *key;
  int32_t value;
} Item;

const Item NULL_ITEM = {NULL, 0};

void print_item(Item item) { printf("\t{ %s, %d },\n", item.key, item.value); }

void insert(Item map[], int length, char *key, int32_t value) {
  Item tmp_item = {key, value};
  map[get_index(key)] = tmp_item;
}

int main(int argc, char *argv[]) {
  int length = 16;
  Item map[] = {
      NULL_ITEM, NULL_ITEM, NULL_ITEM, NULL_ITEM, NULL_ITEM, NULL_ITEM,
      NULL_ITEM, NULL_ITEM, NULL_ITEM, NULL_ITEM, NULL_ITEM, NULL_ITEM,
      NULL_ITEM, NULL_ITEM, NULL_ITEM, NULL_ITEM,
  };

  insert(map, length, "bar", 42);
  insert(map, length, "jane", 100);
  insert(map, length, "foo", 10);
  insert(map, length, "bazz", 36);
  insert(map, length, "buzz", 7);
  insert(map, length, "bob", 11);

  printf("{\n");
  for (int i = 0; i < length; i++) {
    if (sizeof(map[i]) != 16)
      print_item(NULL_ITEM);
    else
      print_item(map[i]);
  }

  printf("}\n");
  printf("hello, world\n");

  return EXIT_SUCCESS;
}
