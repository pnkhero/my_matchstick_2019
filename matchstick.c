/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "./include/my.h"

int main(int ac, char **av)
{
    int line = 0;
    struct map m;
    struct game g;
    int matchstick_return_value = 0;

    if (error_arg(ac, av) == 84)
        return (84);
    line = my_getnbr(av[1]);
    g.matches = my_getnbr(av[2]);
    m.nb_cols = (line * 2) + 1;
    m.nb_rows = line + 2;
    m.map = malloc_map(&m);
    load_map(&m);
    g.end_game = nbr_matches(&m);
    printab(&m);
    while(g.end_game > 0) {
        matchstick_return_value = my_matchstick(&g, &m);
        if (matchstick_return_value == -1)
            return (0);
        if (matchstick_return_value == 1)
            return (1);
        if (matchstick_return_value == 2)
            return (2);  
    }
    return (0);
}
