/*
** EPITECH PROJECT, 2019
** my_str_isnum.c
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 48 && str[i] <= 57) || (str[i] == '\n')) {
            i++;
        } else {
            return (1);
        }
    }
    return (0);
}
