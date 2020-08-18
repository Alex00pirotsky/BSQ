//
// Created by zeus on 13.07.2020.
//

#include "stuff.h"
#include <stdio.h>

opt opti;

/// L = SQRT(pow_2(x1 - x2) + pow_2(Y1 - Y2)) РАстояние между точками
void sq_creator(int x, int y, int len, sqr *bible)
{
    bible->x1_y1[0] = x;
    bible->x1_y1[1] = y;
    bible->len      = len;
}
void pr_2d(char const **root)
{
    int i;
    i = 0;
    while (root[i])
    {
        printf("%s\n", root[i]);
        i++;
    }
}
int     try_draw(char **root, int x, int y, int till, char opt)
{
    int till_x;
    int till_y;
    int buf;

    buf = x;

    till_x = x + till;
    till_y = y + till;
    if (till_y < opti.level && till_x < opti.line)
    {
        while (y < till_y)
        {
            x = buf;
            while (x < till_x)
            {
                if (root[y][x] == 'o')
                    return (0);
                (opt ) ? root[y][x] = opt : 0;
                x++;
            }
            y++;
        }
        return (1);
    }
    return (0);

}

void    u_l_try(int const x_r, int const y_r, char **root, sqr *bible)
{
    int wall;
    int x;
    int y;

    y = y_r + 1;
    x = x_r + 1;
    wall = 1;
    if (x >= 0 && y >= 0 && try_draw(root, x, y, wall, 0))
    {
        while (try_draw(root, x, y, wall+1, 0))
            wall++;
    }
    (bible->len < wall || bible->len <= wall && y < bible->x1_y1[1]) ? sq_creator(x,y,wall,bible) : 0;
}

void    d_r_try(int const x_r, int const y_r, char **root, sqr *bible)
{
    int x;
    int y;
    int tm_x;
    int tm_y;
    int wall;

    y = y_r - 1;
    x = x_r - 1;
    wall = 1;
    if (x >= 0 && y >= 0 && try_draw(root, x, y, wall, 0))
    {
        while (x + y > 0)
        {
            (y > 0 ) ? tm_y = y - 1 : 0;
            (x > 0 ) ? tm_x = x - 1 : 0;
            if (x >= 0 && y >= 0 && try_draw(root, tm_x, tm_y, wall+1, 0))
            {
                ++wall;
                y = tm_y;
                x = tm_x;
            }
            else
                break;
        }
    }
    (bible->len < wall || bible->len <= wall && y < bible->x1_y1[1]) ? sq_creator(x,y,wall,bible) : 0;
}
void    finde_devil(int fir_p, int sec_p, coor *points, sqr *angel)
{
    int mid_p;
    int x;
    int y;

    mid_p = fir_p + 1;
    while (mid_p <= sec_p)
    {
        if(points->x_y[mid_p][1] <= points->x_y[sec_p][1])
        {
            x = points->x_y[mid_p][0];
            y = points->x_y[fir_p][1];

            if (points->x_y[fir_p][0] >= x)
                u_l_try(x, y, points->root, angel);

            y = points->x_y[sec_p][1];

            if (points->x_y[sec_p][0] <= x)
                d_r_try(x,y, points->root, angel);
        }
        mid_p++;
    }
}

sqr first_last(coor *points)
{
    sqr  follen;
    int     i;
    int     j;

    follen.len = 1;
    i = 0;
    while (i < points->all_poin - 1)
    {
        j = i + 1;
        while (j < points->all_poin)
        {
            finde_devil(i,j,points, &follen);
            j++;
        }
        i++;
    }
    points->x_y = NULL;
    free(points->x_y);
    return (follen);
}
void    game_play(coor *points)
{
    sqr     velzi;
    velzi = first_last(points);
    try_draw(points->root,velzi.x1_y1[0], velzi.x1_y1[1],velzi.len,'#');
    pr_2d((const char **) points->root);
}
char *tmp(int what)
{
    char **tmp;
    tmp = make_duble(60,11);
    tmp[0] = "/home/zeus/CLionProjects/bsq/examples/e1x.txt";
    tmp[1] = "/home/zeus/CLionProjects/bsq/examples/e2x.txt";
    tmp[2] = "/home/zeus/CLionProjects/bsq/examples/e3x.txt";
    tmp[3] = "/home/zeus/CLionProjects/bsq/examples/e4x.txt";
    tmp[4] = "/home/zeus/CLionProjects/bsq/examples/e9x.txt";
    tmp[5] = "/home/zeus/CLionProjects/bsq/examples/ex.txt";
    tmp[6] = "/home/zeus/CLionProjects/bsq/examples/eex.txt";
    tmp[7] = "/home/zeus/CLionProjects/bsq/examples/eeex.txt";
    tmp[8] = "/home/zeus/CLionProjects/bsq/examples/eeeex.txt";
    tmp[9] = "/home/zeus/CLionProjects/bsq/examples/eeeeex.txt";
    tmp[10]= "/home/zeus/CLionProjects/bsq/examples/eeeeeex.txt";
    return tmp[what];
}
int     main(int argc, char **argv)
{

    char    *path = argv[1];
    char    *vect;
    coor    points;
    if (argv[1] && argv[2] == NULL)
    {
        vect = (path) ? get_fr_file(path) : 0;
        opti   = counting_op(vect);
        points = take_coord(vect,&opti);
        game_play(&points);
    }
    else if (argv[2])
        printf("Only one arg frome examples dir\n");
    else
        printf("Wrong or no arg\n");
    return (0);
}