/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** main
*/

#include "../include/hashtable.h"

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    printf ("test hash %d\n", ht->hash("HOLA", 10));
    printf ("test pos %d\n", ht->hash("HOLA", 10) % 10);
    printf ("test pos of HOLAfde %d\n", ht->hash("HOLAfde", 10) % 10);
    ht_insert(ht, "HOLA", "HOLA");
    ht_insert(ht, "HOLA1", "HOLA1");
    ht_insert(ht, "HOLA2", "HOLA2");
    ht_insert(ht, "HOLA3", "HOLA3");
    ht_insert(ht, "HOLAfde", "HOLAcef2");
    ht_insert(ht, "HvtbyOLA2", "HOrftvbLA2");
    ht_insert(ht, "bull1", "bull1");
    ht_insert(ht, "bull2", "bull2");
    ht_insert(ht, "bull3", "bull3");
    int return_val = 0;
    ht_dump(ht);
    if (return_val == 1)
        printf("it did not work \n");
    delete_hashtable(ht);
    return 0;
}
