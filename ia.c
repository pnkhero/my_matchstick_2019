/*
** EPITECH PROJECT, 2020
** ia.c
** File description:
** ia
*/

#include "./include/my.h"

int ia_remove(struct map *m)
{
    int j = 0;

    for (int i = 0; i <= m->nb_rows - 2; i++) {
        j = my_strlen(m->map[i]) - 2;
        for (; j > 0; j--) {
            if (m->map[i][j] == '|') {
                m->map[i][j] = ' ';
                recap_ia(i);
                return (0);
            }
        }
    }
    return (0);
}

int ia(struct game *g, struct map *m)
{
    my_putstr("AI's turn...\n");
    ia_remove(m);
    printab(m);
    g->end_game = nbr_matches(m);
    if (g->end_game == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}