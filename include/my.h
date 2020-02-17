/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

struct map
{
    char **map;
    int nb_cols;
    int nb_rows;
};

struct game
{
    int lineplay;
    int matchesplay;
    int end_game;
    int matches;
};

char **malloc_map(struct map *m);
void load_leftright_line(struct map *m);
void load_firstlast_line(struct map *m);
void load_space(struct map *m);
void printab(struct map *m);
int my_putchar(char c);
int my_putstr_error(char *c);
int my_putstr(char const *str);
int my_getnbr(char *str);
void load_match_map(struct map *m);
int player_input(struct game *g);
int my_getnbr_oneline(char *str);
int error_line(struct map *m, struct game *g);
int my_strlen(char const *str);
void load_map(struct map *m);
int my_str_isnum(char const *str);
int get_matches(struct game *g);
int player(struct map *m, struct game *g);
void remove_matches(struct map *m, struct game *g);
int nbr_matches(struct map *m);
int strlen_matches(char *str);
int my_matchstick(struct game *g, struct map *m);
int ia(struct game *g, struct map *m);
int my_putnbr(int nb);
int error_matches(struct map *m, struct game *g);
void recap_turn(struct game *g, int id);
int count_stick_inline(struct map *m, struct game *g);
int ia_remove(struct map *m);
void recap_player(struct game *g);
void recap_ia(int i);
void recap_remove(struct map *m, struct game *g);
int error_arg(int ac, char **av);
int count_stick_lineia(struct map *m, char *str, int i);
void ia_remove_more_at_last(struct map *m, int i, struct game *g);
void ia_remove_suit(struct map *m, int i, struct game *g);

#endif /* !MY_H_ */
