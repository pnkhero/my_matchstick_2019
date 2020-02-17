/*
** EPITECH PROJECT, 2020
** recap_turn
** File description:
** recap_turn
*/

#include "./include/my.h"

void recap_player(struct game *g)
{
    my_putstr("Player removed ");
    my_putnbr(g->matchesplay);
    my_putstr(" match(es) from line ");
    my_putnbr(g->lineplay);
    my_putchar('\n');
}

void recap_ia(int i)
{
    my_putstr("AI removed ");
    my_putnbr(1);
    my_putstr(" match(es) from line ");
    my_putnbr(i);
    my_putchar('\n');
}

void recap_remove(struct map *m, struct game *g)
{
    recap_player(g);
    remove_matches(m, g);
    printab(m);
}