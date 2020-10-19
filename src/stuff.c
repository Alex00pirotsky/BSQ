//
// Created by zeus on 13.07.2020.
//
#include "../headers/stuff.h"
#include <stdio.h>
#include <math.h>







char    **make_duble(int len, int levels)
{
    char **root;
    int i;

    root = malloc(sizeof(char *) * levels);
    i = 0;
    while (i < levels)
    {
        root[i] = malloc(sizeof(char) * len);
        i++;
    }
    return root;
}
int     **make_du_in(int len, int levels)
{
    int **root;
    int i;

    root = (int **)malloc(sizeof(int *) * levels);
    i    = 0;
    while (i < levels)
    {
        root[i] = (int *)malloc(sizeof(int) * len);
        i++;
    }
    return root;
}


int     ft_str_len(char const *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return i;
}
void    wr(int opt, char *what)
{
    write(opt, what, ft_str_len(what));
}
int     is_it_wh_sp(char w)
{
    return (w == ' ' || w == '\n' || w == '\t');
}
int     is_it(char w, char opt)
{
    return (w == opt);
}
opt     counting_op(char *str)
{
    opt opti;
    int i;

    i = 0;
    opti.points = 0;
    opti.level  = 0;
    opti.line   = 0;
    while (str[i])
    {
        if (is_it_wh_sp(str[i]))
        {
            opti.level += 1;
            (opti.line == 0 ) ? opti.line = i : 0;
        }
        if(is_it(str[i], 'o'))
            opti.points++;
        i++;
    }
    opti.level += 1;
    opti.line  += 1;
    return opti;
}
coor take_coord(char *vect, opt *opti)
{
    coor points;
    int x,y,l;

    y = 0;
    x = 0;
    l = 0;
    points.x_y  = make_du_in(2, opti->points);
    points.root = make_duble(opti->line + 2,opti->level + 2);
    while (*vect)
    {
        if (is_it_wh_sp(*vect))
        {
            points.root[y][x] = '\0';
            vect++;
            y++;
            x = 0;
        }
        if (*vect == 'o')
        {
            points.x_y[l][0] = x;
            points.x_y[l][1] = y;
            l++;
        }
        points.root[y][x] = *vect;
        vect++;
        x++;
    }
    vect           = NULL;
    free(vect);
    points.root[y] = NULL;
    points.x_y[l]  = NULL;
    points.all_poin = l;
    return points;
}
