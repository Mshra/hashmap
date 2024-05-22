# Hashmap

Programmed the [Hashmap](https://en.wikipedia.org/wiki/Hash_table#:~:text=In%20computing%2C%20a%20hash%20table,that%20maps%20keys%20to%20values.), data structure from scratch using C.

---
- Used the [FNV-1a](https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function) algorithm for building hashes.
- Avoids collision using [Linear Probing](https://en.wikipedia.org/wiki/Linear_probing) technique.
- Able to perform operations and call methods such as,
    - Insert
    - Delete
    - Print
---
**How does it work?**

Started by defining elements of Hashmap as **Item**.

```
typedef struct {
  char *key;
  int32_t value;
  int isEmpty;
} Item;
```

[link](https://benhoyt.com/writings/hash-table-in-c/)
