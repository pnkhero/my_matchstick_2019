/*
** EPITECH PROJECT, 2020
** player.c
** File description:
** player
*/

#include "./include/my.h"

int player_input(struct game *g)
{
    g->lineplay = 0;
    char *buffer = NULL;
    size_t bufsize = 0;

    if (getline(&buffer, &bufsize, stdin) == -1) {
        return (-1);
    }
    if (my_str_isnum(buffer) > 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (-2);
    }
    g->lineplay = my_getnbr_oneline(buffer);
    return (g->lineplay);
}

int get_matches(struct game *g)
{
    g->matchesplay = 0;
    char *bufm = NULL;
    size_t bufsizem = 0;

    my_putstr("Matches: ");
    if (getline(&bufm, &bufsizem, stdin) == -1) {
        return (-1);
    }
    if (my_str_isnum(bufm) > 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (-2);
    }
    g->matchesplay = my_getnbr_oneline(bufm);
    return (g->matchesplay);
}

int count_stick_inline(struct map *m, struct game *g)
{
    int x = 0;
    int count = 0;

    while(x < m->nb_cols) {
        if (m->map[g->lineplay][x] == '|') {
            count++;
        }
        x++;
    }
    return (count);
}

void remove_matches(struct map *m, struct game *g)
{
    int matches = g->matchesplay;
    int i = 0;
    int nb_colss = m->nb_cols;

    while (nb_colss > i) {
        if (m->map[g->lineplay][nb_colss] == '|' && matches > 0) {
            m->map[g->lineplay][nb_colss] = ' ';
            matches = matches - 1;
    }
    nb_colss--;
    }
}

int player(struct map *m, struct game *g)
{
    int x = 0;

    my_putstr("Your turn:\n");
    while (x < 1) {
        my_putstr("Line: ");
        g->lineplay = player_input(g);
        if (g->lineplay == -1)
            return (-1);
        x = error_line(m, g);
        if (x > 0) {
            g->matchesplay = get_matches(g);
            if (g->matchesplay == -1)
                return (-1);
            x = error_matches(m, g);
        }
    }
    recap_remove(m, g);
    g->end_game = nbr_matches(m);
    if (g->end_game == 0) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    return (0);
}