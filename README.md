# Hashmap

Programmed the [Hashmap](https://en.wikipedia.org/wiki/Hash_table#:~:text=In%20computing%2C%20a%20hash%20table,that%20maps%20keys%20to%20values.), data structure from scratch using C.

---

- Used the [FNV-1a](https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function) for building hashes.
- Avoids collision using [Linear Probing](https://en.wikipedia.org/wiki/Linear_probing) technique.
- Able to perform operations and call methods such as,
    - Insert
    - Delete
    - Print

---
**How does it work?**

## Hashing(FNV-1a) - from wikipedia
>algorithm fnv-1a is
>
>    hash := FNV_offset_basis
>
>    for each byte_of_data to be hashed do
>
>        hash := hash XOR byte_of_data
>
>        hash := hash × FNV_prime
>
>    return hash 

We start by defining elements in the Hashmap i.e. A key-value pair and call it **Item**.

---
## Programming the Hashmap
```c
typedef struct {
  char *key;
  int32_t value;
  int isEmpty;
} Item;
```
Using this, we define a constant called **NULL_ITEM** to avoid handling with garbage values,
present in the set of Hashmap.

Now creating a Hashmap data type using struct which is defined as
```c
typedef struct {
  int length;
  Item map[];
} Hash_Map;
```

Initiliaze the 
