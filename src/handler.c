/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** hash_handle
*/

#include "../include/hashtable.h"

static int comp(bucket_t *head, char *key, char *value)
{
    if (my_strcmp(head->user, key) == 0) {
        free(head->value);
        head->value = my_strdup(value);
        return 0;
    }
    return 0;
}

static int init(hashtable_t *ht, char *key, char *value, int pos)
{
    bucket_t *new_bucket;
    bucket_t *old_head = ht->bucket[pos % ht->size];

    new_bucket = malloc(sizeof(bucket_t));
    if (new_bucket == NULL)
        return 1;
    new_bucket->user = old_head->user;
    new_bucket->value = old_head->value;
    new_bucket->next = old_head->next;
    old_head->user = my_strdup(key);
    old_head->value = my_strdup(value);
    old_head->next = new_bucket;
    return 0;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int pos = ht->hash(key, ht->size) % ht->size;
    bucket_t *head = ht->bucket[pos % ht->size];

    if (ht->bucket[pos % ht->size]->user == NULL) {
        ht->bucket[pos % ht->size]->user = my_strdup(key);
        ht->bucket[pos % ht->size]->value = my_strdup(value);
        return 0;
    }
    while (head != NULL) {
        if (key && head->user) {
            comp(head, key, value);
        }
        head = head->next;
    }
    init(ht, key, value, pos);
    return 0;
}

static int edge(int pos, bucket_t *head, hashtable_t *ht, char *key)
{
    if (my_strcmp(head->user, key) == 0) {
        free(head->value);
        free(head->user);
        if (head->next != NULL) {
            ht->bucket[pos % ht->size] = head->next;
            free(head);
        } else {
            head->value = NULL;
            head->user = NULL;
        }
    }
    return 0;
}

static int found(bucket_t *head, int pos, hashtable_t *ht, char *key)
{
    if (head && head->user) {
        edge(pos, head, ht, key);
        return 0;
    }
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int pos = ht->hash(key, ht->size);
    bucket_t *head = ht->bucket[pos % ht->size];
    bucket_t *current = head;
    bucket_t *prev = NULL;

    found(head, pos, ht, key);
    while (current != NULL) {
        if (my_strcmp(current->user, key) == 0) {
            free(current->user);
            free(current->value);
            prev->next = current->next;
            free(current);
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return 1;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int pos = ht->hash(key, ht->size);
    bucket_t *bucket = ht->bucket[pos % ht->size];

    while (bucket != NULL) {
        if (my_strcmp(bucket->user, key) == 0) {
            return bucket->value;
        }
        bucket = bucket->next;
    }
    return NULL;
}

static int nested(bucket_t *current, hashtable_t *ht)
{
    while (current->next != NULL) {
        if (current->value != NULL) {
            my_putstr("> ");
            show_number(ht->hash(current->user, ht->size));
            my_putstr(" - ");
            my_putstr(current->value);
            my_putstr("\n");
        }
        current = current->next;
    }
    return 0;
}

void ht_dump(hashtable_t *ht)
{
    bucket_t **array = ht->bucket;
    bucket_t *current;

    for (int i = 0; i < ht->size; i++) {
        current = array[i];
        my_putstr("[");
        show_number(i);
        my_putstr("]:\n");
        if (current->value != NULL) {
            nested(current, ht);
        }
    }
}
