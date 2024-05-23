#include "fnv-1a.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_index(char *key, int length) { return (FNV_ONEA_64(key) & length); }

typedef struct {
  char *key;
  int32_t value;
  int isEmpty; /* 1 if empty, else 0 */
} Item;

typedef struct {
  int length;
  Item map[];
} Hash_Map;

const Item NULL_ITEM = {NULL, 0, 1};

void allocate_NULL_ITEM(Hash_Map *hmap, int length) {
  for (int i = 0; i < length; i++) {
    hmap->map[i] = NULL_ITEM;
  }
}

void print_item(Item item) { printf("  { %s, %d },\n", item.key, item.value); }

void print_hmap(Hash_Map *hmap) {
  printf("{\n");
  for (int i = 0; i < hmap->length; i++) {
    if ((hmap->map[i]).isEmpty) {
      print_item(NULL_ITEM);
    } else {
      print_item(hmap->map[i]);
    }
  }
  printf("}\n");
}

void insert(Hash_Map *hmap, char *key, int32_t value) {
  int index = get_index(key, hmap->length);
  Item tmp = {key, value, 0};

  // normal insert, no collision our out of index.
  if ((index < hmap->length) && ((hmap->map[index]).isEmpty)) {
    hmap->map[index] = tmp;
  }

  // getting out of index i.e. index == length
  if (index == hmap->length) {
    Hash_Map *tmp_hmap = (Hash_Map *)malloc(sizeof(Hash_Map));
    if (tmp_hmap == NULL) {
      printf("memory allocation failed!\n");
      exit(EXIT_FAILURE);
    }

    printf("%d %d\n", tmp_hmap->length, hmap->length);
    allocate_NULL_ITEM(tmp_hmap, tmp_hmap->length);

    for (int i = 0; i < hmap->length; i++) {
      if ((hmap->map[i]).key != (NULL_ITEM.key)) {
        tmp_hmap->map[get_index((hmap->map[i]).key, tmp_hmap->length)] =
            hmap->map[i];
      }
    }
    insert(tmp_hmap, key, value);
    hmap = tmp_hmap;
  }

  if ((!(hmap->map[index]).isEmpty)) {
    while ((hmap->map[index]).isEmpty) {
      if (index == hmap->length) {
        Hash_Map *tmp_hmap = (Hash_Map *)malloc(sizeof(Hash_Map));
        if (tmp_hmap == NULL) {
          printf("memory allocation failed!\n");
          exit(EXIT_FAILURE);
        }

        printf("%d %d\n", tmp_hmap->length, hmap->length);
        allocate_NULL_ITEM(tmp_hmap, tmp_hmap->length);

        for (int i = 0; i < hmap->length; i++) {
          if ((hmap->map[i]).key != (NULL_ITEM.key)) {
            tmp_hmap->map[get_index((hmap->map[i]).key, tmp_hmap->length)] =
                hmap->map[i];
          }
        }
        hmap = tmp_hmap;
        break;
      }
      index++;
    }
  }
}

Hash_Map *init_hashmap() {
  Hash_Map *tmp_hmap = (Hash_Map *)malloc(sizeof(Hash_Map));
  if (tmp_hmap == NULL) {
    printf("memory allocation failed!\n");
    exit(EXIT_FAILURE);
  }

  tmp_hmap->length = 1;
  allocate_NULL_ITEM(tmp_hmap, tmp_hmap->length);
  return tmp_hmap;
}

void delete(Hash_Map *hmap, char *key) {
  hmap->map[get_index(key, hmap->length)] = NULL_ITEM;
}

int main(int argc, char *argv[]) {
  Hash_Map *hmap = init_hashmap();

  insert(hmap, "bar", 42);
  insert(hmap, "jane", 100);

  return EXIT_SUCCESS;
}
