/*
** EPITECH PROJECT, 2020
** create_map
** File description:
** create_map
*/

#include "./include/my.h"

void load_space(struct map *m)
{
    int i = 0;
    int j = 0;

    while (i < m->nb_rows) {
        while (j < m->nb_cols) {
            m->map[i][j] = ' ';
            j++;
        }
        m->map[i][j] = '\0';
        j = 0;
        i++;
    }
}

void load_leftright_line(struct map *m)
{
    int y = 0;

    while (y < m->nb_rows) {
        m->map[y][0] = '*';
        m->map[y][m->nb_cols - 1] = '*';
        y++;
    }
}

void load_firstlast_line(struct map *m)
{
    int y = 0;
    int x = 0;

    while (x < m->nb_cols) {
        m->map[y][x] = '*';
        x++;
    }
    x = 0;
    while (x < m->nb_cols) {
        m->map[m->nb_rows - 1][x] = '*';
        x++;
    }
}

void load_match_map(struct map *m)
{
    int y = 1;
    int x = 0;
    int n = 1;
    int nb_rowscopy = m->nb_rows;
    
    while ((nb_rowscopy - 2) >= y) {
        x = 0;
        while ((x + n) < (m->nb_cols - n)) {
            m->map[nb_rowscopy - 2][x + n] = '|';
            x++;
        }
        n = n + 1;
        nb_rowscopy--;
    }
}

void load_map(struct map *m)
{
    load_space(m);
    load_leftright_line(m);
    load_firstlast_line(m);
    load_match_map(m);
}