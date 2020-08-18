//
// Created by zeus on 13.07.2020.
//

#ifndef BSQ_FIL_H
#define BSQ_FIL_H

#include "stuff.h"

#include "sys/stat.h"
#include <fcntl.h>

#include "sys/types.h"

#include <fcntl.h>

void    re_pr       (char *path);
char *get_fr_file(char *path);
int get_fl_size(char *path);
void    wri_t_f     (char *path, char *wh);
void    ape_t_f     (char *path, char *wh);



#endif //BSQ_FIL_H
