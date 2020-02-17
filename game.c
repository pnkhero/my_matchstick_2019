/*
** EPITECH PROJECT, 2020
** check_win
** File description:
** game
*/

#include "./include/my.h"

int nbr_matches(struct map *m)
{
    int i = 0;
    int j = 0;
    int count_matches = 0;

     while (i < m->nb_rows) {
        while (j < m->nb_cols) {
            if (m->map[i][j] == '|') {
                count_matches++;
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (count_matches);
}

int my_matchstick(struct game *g, struct map *m)
{
    int value_return = 0;
    
    value_return = player(m, g);
    if (value_return == -1) {
        return (-1);
    }
    if (value_return == 2) {
        return (2);
    }
    else if (ia(g, m) == 1) {
        return (1);
    }
    return (0);
}