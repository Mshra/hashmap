#include "fnv-1a.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int get_index(char *key) { return (FNV_ONEA_64(key) % 16); }

typedef struct {
  char *key;
  int32_t value;
} Item;

typedef struct {
  int length;
  Item map[];
} Hash_Map;

const Item NULL_ITEM = {NULL, 0};

void print_item(Item item) { printf("  { %s, %d },\n", item.key, item.value); }

void print_hmap(Hash_Map *hmap) {
  printf("{\n");
  for (int i = 0; i < hmap->length; i++) {
    if (sizeof(hmap->map[i]) != sizeof(Item))
      print_item(NULL_ITEM);
    else
      print_item(hmap->map[i]);
  }
  printf("}\n");
}

void insert(Hash_Map *hmap, char *key, int32_t value) {
  Item tmp_item = {key, value};
  hmap->map[get_index(key)] = tmp_item;
}

Hash_Map *create_hashmap(int length) {
  Hash_Map *tmp_map = (Hash_Map *)malloc(sizeof(Hash_Map));
  tmp_map->length = length;

  for (int i = 0; i < length; i++) {
    tmp_map->map[i] = NULL_ITEM;
  }
  return tmp_map;
}

void delete(Hash_Map *hmap, char *key) {
  hmap->map[get_index(key)] = NULL_ITEM;
}

int main(int argc, char *argv[]) {
  int length = 16;

  Hash_Map *hmap = create_hashmap(16);

  insert(hmap, "bar", 42);
  insert(hmap, "jane", 100);
  insert(hmap, "foo", 10);
  insert(hmap, "bazz", 36);
  insert(hmap, "buzz", 7);
  insert(hmap, "bob", 11);

  print_hmap(hmap);
  return EXIT_SUCCESS;
}
