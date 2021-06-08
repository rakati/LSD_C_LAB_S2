#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdlib.h>

struct t_point
{
    int base;
    int height;
};
typedef struct t_point t_point;


void input(t_point*);
void output(t_point);
char ** array(t_point);
void free_array(t_point,char**);
char** array_input(t_point,char **);
void array_output(t_point,char**);
t_point get_position();
void flood_fill(char**,t_point,t_point,char,char);

#endif
