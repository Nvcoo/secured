/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** my
*/

#include "../include/my.h"

int my_strcmp(const char *s1, const char *s2)
{
    int a;

    for (a = 0; s1[a] != '\0' && s2[a] != '\0'; a++) {
        if (s1[a] != s2[a]) {
            return s1[a] - s2[a];
        }
    }
    return s1[a] - s2[a];
}

int get_nbr(const char *str)
{
    int result = 0;

    while (*str) {
        if (!(*str >= '0' && *str <= '9')) {
            return result;
        }
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}

char *my_strcpy(char *dest, const char *src)
{
    int copy = 0;

    while (src[copy] != '\0') {
        dest[copy] = src[copy];
        copy++;
    }
    dest[copy] = '\0';
    return dest;
}

int my_strlen(const char *dest)
{
    int len = 0;

    while (dest[len] != '\0') {
        len++;
    }
    return len;
}

char *my_strdup(const char *src)
{
    char *copy = malloc(sizeof(char) * my_strlen(src) + 1);

    if (copy == NULL) {
        return NULL;
    }
    my_strcpy(copy, src);
    return copy;
}
