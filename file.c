#include "fil.h"
#include <stdio.h>
void re_pr(char *path)
{
    int len;
    int opt;
    char buf[1024];

    opt = open(path,O_RDONLY,S_IRWXU);
    (opt > 0) ? len = read(opt,buf,1024) : wr(2,"BEDA");
    (opt > 0) ? buf[len] = '\0', write(1,buf,len+1)  : 0;
    close(opt);
}
int get_fl_size(char *path)
{
    int len;
    int opt;
    int sum;
    char *buf;

    buf = malloc(sizeof(char));
    opt  = open(path,O_RDONLY);
    sum = 0;
    if (opt != -1)
    {
        while (len = read(opt, buf, 1))
            sum++;
    }
    buf = NULL;
    free(buf);
    close(opt);
    return sum+1;
}
char *get_fr_file(char *path)
{
    int len;
    int opt;
    char *buf;

    len = get_fl_size(path);
    buf = (char *)malloc(sizeof(char) * len);
    opt  = open(path,O_RDONLY);
    (opt != -1) ? len  = read(opt, buf, len) : 0;
    (opt != -1) ? buf[len] = '\0' : 0;
    close(opt);
    return (opt != -1) ? buf : NULL;
}

char *get_fr_file_param(char *path, int(*f)(char))
{
    int len;
    int opt;
    char *buf;

    buf = (char *)malloc(sizeof(char) * 1024);
    opt  = open(path,O_RDONLY);
    (opt != -1) ? len  = read(opt, buf, 1024) : 0;
    (opt != -1) ? buf[len] = '\0' : 0;
    close(opt);
    return buf;
}
void wri_t_f(char *path, char *wh)
{
    int opt;
    opt = open(path, O_WRONLY | O_CREAT, S_IRWXU);
    (opt > 0) ? wr(opt, wh) : wr(2,"BEDA");
    close(opt);
}
void ape_t_f(char *path, char *wh)
{
    int opt;
    opt = open(path, O_APPEND, S_IRWXU);
    (opt > 0) ? wr(opt, wh) : wr(2,"BEDA");
    close(opt);
}