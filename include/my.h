/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** my
*/

#ifndef INCLUDED_MY_H
    #define INCLUDED_MY_H

    #include "stdlib.h"
    #include <stdio.h>
    #include <unistd.h>
    #include <assert.h>

typedef struct bucket bucket_t;

typedef struct bucket {
    char *user;
    char *value;
    bucket_t *next;
} bucket_t;

int my_strcmp(const char *s1, const char *s2);
int get_nbr(const char *str);
char *my_strcpy(char *dest, const char *src);
int my_strlen(const char *dest);
void my_putchar(char c);
int my_putstr(const char *str);
char *my_strdup(const char *src);
int show_number(int nb);

#endif
