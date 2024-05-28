#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define HT_INITIAL_BASE_SIZE 53

// Les pairs de clef-valeurs (éléments) stockés dans :
typedef struct {
    char* key;
    char *value;
} ht_item;

// La table de hashage stocke un tab de pointeurs sur éléments et des détails :
typedef struct {
    int size;
    int count;
    int base_size;
    ht_item** items;
} ht_hash_table;


// fonctions
ht_hash_table* ht_new();
void ht_del_hash_table(ht_hash_table* ht);


// API de la table de hachage:
void ht_insert(ht_hash_table* ht, const char* key, const char* value);
char* ht_search(ht_hash_table* ht, const char* key);
void ht_delete(ht_hash_table* ht, const char* key);

#endif