/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** hash
*/

#include "../include/hashtable.h"

int hash(char *key, int len)
{
    int hash = 4096;
    int i;

    for (i = 0; i < my_strlen(key); i++) {
        hash = ((hash << 5) + hash) + key[i] % len;
    }
    if (hash < 0)
        hash *= -1;
    return hash;
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *new_table = malloc(sizeof(hashtable_t));
    int i = 0;

    new_table->size = len;
    new_table->bucket = malloc(sizeof(bucket_t *) * len);
    if (new_table->bucket == NULL) {
        free(new_table);
        return NULL;
    }
    for (i = 0; i < len; i++) {
        new_table->bucket[i] = malloc(sizeof(bucket_t));
        if (new_table->bucket[i] == NULL)
            return NULL;
        new_table->bucket[i]->next = NULL;
        new_table->bucket[i]->value = NULL;
        new_table->bucket[i]->user = NULL;
    }
    new_table->hash = hash;
    return new_table;
}

static int bucket_free(bucket_t *current)
{
    if (current->user && current->value) {
        free(current->user);
        free(current->value);
    }
    return 0;
}

void delete_hashtable(hashtable_t *ht)
{
    int i = 0;
    bucket_t *current;
    bucket_t *temp;

    if (!ht)
        return;
    for (i = 0; i < ht->size; i++) {
        current = ht->bucket[i];
        while (current != NULL) {
            bucket_free(current);
            temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->bucket);
    free(ht);
}
