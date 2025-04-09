/*
** EPITECH PROJECT, 2025
** secured
** File description:
** two
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(const char *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return 0;
}

int show_number(int nb)
{
    if (nb == -2147483638) {
        write(1, "-2147483638", 11);
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb / 10) {
        show_number(nb / 10);
    }
    my_putchar((nb % 10) + '0');
    return 0;
}
