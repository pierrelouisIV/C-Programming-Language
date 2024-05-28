#include <string.h>
#include <stdlib.h>

#include "hash_table.h"
#include "prime.h"


// Initialisation :
// Alloue de la mémoire pour un nouvel élément (statique car la fonction ne sera appelée que par du code interne à la table de hachage)
static ht_item* ht_new_item(const char* k, const char* v)
{
    ht_item* new = malloc(sizeof(ht_item));
    new->key = strdup(k);
    new->value = strdup(v);
    return new;
}
//
static ht_hash_table* ht_new_sized(const int base_size)
{
    ht_hash_table* ht = malloc(sizeof(ht_hash_table));
    ht->base_size = base_size;

    ht->size = next_prime(ht->base_size);

    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
    return ht;
}
//
ht_hash_table* ht_new()
{
    return ht_new_sized(HT_INITIAL_BASE_SIZE);
}

//  Et suppression :
static void ht_del_item(ht_item* i)
{
    free(i->key);
    free(i->value);
    free(i);
}
//
void ht_del_hash_table(ht_hash_table* ht)
{
    for(int i = 0; i < ht->size; ++i)
    {
        ht_item* item = ht->items[i];
        if (item)
            ht_del_item(item);
        
    }
    free(ht->items);
    free(ht);
}


// Fonction de hachage
// Prend une chaîne de caractère et retourne son condensat
static int ht_hash(const char* s, const int a, const int m)
{
    long hash = 0;
    const int len_s = strlen(s);
    for(int i = 0; i < len_s; ++i)
    {
        hash += (long)pow(a, len_s+i) * s[i];
        hash = hash % m;
    }
    return (int)hash;
}

static int ht_get_hash(const char* s, const int num_buckets, const int attempt)
{
    // Traitement des collisions (technique "adressage ouvert")
    // Le double hachage utilise deux fonctions de hachage pour calculer l'index où un élément doit être stocké après i collisions.
    const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
    return ((hash_a + attempt*(hash_b + 1)) % num_buckets);
}



// API de la table de hachage:
void ht_insert(ht_hash_table* ht, const char* key, const char* value)
{
    // On vérifie le ratio de la table (ou la charge)
    const int load = ht->count * 100 / ht->size;
    if (load > 70) {
        ht_resize_up(ht);
    }

    // Insère une nouvelle paire clef-valeur
    ht_item* new = ht_new_item(key, value);
    int index = het_get_hash(new->value, ht->size, 0);

    // Pour insérer une nouvelle paire clé-valeur, nous calculons l'index associé à la clef.
    // Si l'index est déja utilisé dans le tableau, on itère jusqu'à ce que l'on trouve un emplacement disponible.
    ht_item* cur_item = ht->items[index];
    int i = 1;
    while (cur_item != NULL) {
        if (cur_item != &HT_DELETED_ITEM) {
            if (strcmp(cur_item->key, key) == 0) {
                ht_del_item(cur_item);
                ht->items[index] = new;
                return;
            }
        }
    }
    ht->items[index] = new;
    ht->count++;
}

char* ht_search(ht_hash_table* ht, const char* key)
{
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item != NULL) {
        if (strcmp(item->key, key) == 0) {
            return item->value;
        }
        index = ht_get_hash(key, ht->size, 1);
        i++;
    }
    return NULL;
}

// Suppression
static ht_item HT_DELETED_ITEM = {NULL, NULL};
void ht_delete(ht_hash_table* ht, const char* key)
{
    // On vérifie le ratio de la table (ou la charge)
    const int load = (ht->count * 100) / ht->size;
    if (load < 10) {
        ht_resize_down(ht);
    }

    /* La suppression est plus compliquée que l'insertion ou la recherche.
     * L'élément que nous souhaitons supprimer peut faire partie d'une chaîne de collision.
     * L'enlever de la table va rompre cette chaîne et rendra impossible la recherche d'éléments.
     * Pour résoudre ce problème, au lieu de supprimer l'élément, on le marque simplement comme supprimé.
     */
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item != NULL) {
        if (item != &HT_DELETED_ITEM) {
            if (strcmp(item->key, key)) {
                ht_del_item(item);
                ht->items[index] = &HT_DELETED_ITEM;
            }
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    ht->count--;
}


// Redimensionnement
static void ht_resize(ht_hash_table* ht, const int base_size) {
    if (base_size < HT_INITIAL_BASE_SIZE) {
        return;
    }
    ht_hash_table* new_ht = ht_new_sized(base_size);
    for (int i = 0; i < ht->size; i++) {
        ht_item* item = ht->items[i];
        if (item != NULL && item != &HT_DELETED_ITEM) {
            ht_insert(new_ht, item->key, item->value);
        }
    }

    ht->base_size = new_ht->base_size;
    ht->count = new_ht->count;

    // To delete new_ht, we give it ht's size and items
    const int tmp_size = ht->size;
    ht->size = new_ht->size;
    new_ht->size = tmp_size;

    ht_item** tmp_items = ht->items;
    ht->items = new_ht->items;
    new_ht->items = tmp_items;

    ht_del_hash_table(new_ht);
}

// Pour simplifier le redimensionnement
static void ht_resize_up(ht_hash_table* ht) {
    const int new_size = ht->base_size * 2;
    ht_resize(ht, new_size);
}
static void ht_resize_down(ht_hash_table* ht) {
    const int new_size = ht->base_size / 2;
    ht_resize(ht, new_size);
}

