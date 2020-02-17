/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include "./include/my.h"

int error_arg(int ac, char **av)
{
    if (ac > 3) {
        my_putstr_error("Too much arguments\n");
        return (84);
    }
    if (ac < 2) {
        my_putstr_error("Too few arguments\n");
        return (84);
    }
    if (my_str_isnum(av[1]) == 1) {
        my_putstr_error("Invalid argument");
        return (84);
    }
    if (my_str_isnum(av[2]) == 1) {
        my_putstr_error("Invalid argument");
        return (84);
    }
    return (0);
}

int error_line(struct map *m, struct game *g)
{
    if (g->lineplay == 0 || g->lineplay >= m->nb_rows) {
            my_putstr("Error: this line is out of range\n");
            return (-1);
    } else {
        return (g->lineplay);
    }
}

int error_matches(struct map *m, struct game *g)
{
    int count = count_stick_inline(m, g);

    if (g->matchesplay == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (-1);
    }
    if (g->matchesplay > g->matches) {
        my_putstr("Error: you cannot remove more than ");
        my_putnbr(g->matches);
        my_putstr(" Matches per turn\n");
        return (-1);
    }
    if (count < g->matchesplay) {
        my_putstr("Error: not enough matches on this line\n");
        return (-1);
    }
    return (g->matchesplay);
}