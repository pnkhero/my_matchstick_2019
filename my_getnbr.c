/*
** EPITECH PROJECT, 2020
** mygetnbr.c
** File description:
** my_getnbr
*/

#include "./include/my.h"

int my_getnbr(char *str)
{
    int nega = 1;
    int nbr = 0;
    int i = 0;

    while (str[i] == '0' || str[i] == '-') {
        if (str[i] == '-') {
            nega = nega * -1;
        }
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10;
            nbr = str[i] - '0' + nbr;
            i++;
        }
        else
            return (nbr * nega);
    }
    return (nbr * nega);
}