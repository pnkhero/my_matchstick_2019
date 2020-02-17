/*
** EPITECH PROJECT, 2020
** create_tab
** File description:
** create_tab
*/

#include "./include/my.h"

char **malloc_map(struct map *m)
{
    m->map = malloc(sizeof(char *) * m->nb_rows);
    int i = 0;

    if (!m->map) {
        return (NULL);
    }
    while (i < m->nb_rows) {
        m->map[i] = malloc(sizeof(char) * m->nb_cols + 1);
        if (m->map[i] == NULL) {
            return (NULL);
        }
        i++;
    }
    return (m->map);
}

void printab(struct map *m)
{
    int i = 0;
    int j = 0;

     while (i < m->nb_rows) {
        while (j < m->nb_cols) {
            my_putchar(m->map[i][j]);
            j++;
        }
        j = 0;
        my_putstr("\n");
        i++;
    }
    my_putchar('\n');
}