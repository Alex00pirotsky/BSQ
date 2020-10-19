//
// Created by zeus on 13.07.2020.
//

#ifndef BSQ_STUFF_H
#define BSQ_STUFF_H


#include "stuff.h"
#include <unistd.h>
#include <stdlib.h>
#include "fil.h"


typedef struct options
{
    int points;
    int line;
    int level;

}opt;

typedef struct sq
{
    int x1_y1[2];
    int len;

}sqr;
typedef struct coordi
{
    int **x_y; /// x = 0 y = 1
    int all_poin;
    char **root;

}coor;

int     ft_str_len  (char const *str);
int ft_lev_cou(char const **root);
void    ft_putchar  (char c);
char    **make_duble(int len, int levels);
int **make_du_in(int len, int levels);
void    wr          (int opt, char *what);
int     ft_atoi     (char *str);
int     ft_pow      (int val,int n);
int     ft_sqrt     (int val);
void    ft_put_nbr  (int a, char *cargo);
char    *in_t_ch    (int val);
int *counting_opt(char *str);
int     len_to_this (char *str, int (f)(char));
opt counting_op    (char *str);
char    **make2d    (char *vect, int escape ,int levels);
coor take_coord(char *vect, opt *opti);
#endif //BSQ_STUFF_H
