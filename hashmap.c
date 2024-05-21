#include "fnv-1a.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int get_index(char *key, int length) { return (FNV_ONEA_64(key) & length); }

typedef struct {
  char *key;
  int32_t value;
} Item;

typedef struct {
  int length;
  Item map[];
} Hash_Map;

const Item NULL_ITEM = {NULL, 0};

void allocate_NULL_ITEM(Hash_Map *hmap, int length) {
  for (int i = 0; i < length; i++) {
    hmap->map[i] = NULL_ITEM;
  }
}

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
  int index = get_index(key, hmap->length);

  if (index == hmap->length) {
    // make a new array with length( 2 * hmap->length);
    // and elements adjusted to new type of array.
    Item tmp = {key, value};
  }

  // check for linear probing
  if (sizeof(hmap->map[index]) == sizeof(Item)) {
    // perform linear probing.
  } else {
    // normal insert.
  }
}

Hash_Map *new_map(Hash_Map *hmap, Item item) {
  Hash_Map *new_hmap = (Hash_Map *)malloc(sizeof(Item));
  new_hmap->length = 2 * hmap->length;
  allocate_NULL_ITEM(new_hmap, new_hmap->length);

  for (int i = 0; i < hmap->length; i++) {
    if ((hmap->map[i]).key != (NULL_ITEM.key)) {
      new_hmap->map[get_index((hmap->map[i]).key, new_hmap->length)] =
          hmap->map[i];
    }
  }
  insert(new_hmap, item.key, item.value);
  return new_hmap;
}

Hash_Map *create_hashmap() {
  Hash_Map *tmp_map = (Hash_Map *)malloc(sizeof(Hash_Map));
  tmp_map->length = 1;
  allocate_NULL_ITEM(tmp_map, tmp_map->length);
  return tmp_map;
}

void delete(Hash_Map *hmap, char *key) {
  hmap->map[get_index(key, hmap->length)] = NULL_ITEM;
}

int main(int argc, char *argv[]) {
  Hash_Map *hmap = create_hashmap();

  insert(hmap, "bar", 42);
  // insert(hmap, "jane", 100);
  // insert(hmap, "foo", 10);
  // insert(hmap, "bazz", 36);
  // insert(hmap, "buzz", 7);
  // insert(hmap, "bob", 11);

  print_hmap(hmap);
  return EXIT_SUCCESS;
}
