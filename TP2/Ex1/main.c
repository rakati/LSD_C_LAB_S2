#include "header.h"

int main(){
    t_point T,S;
    printf("Please enter the dimensions of the array:\n");
    input(&T);
    output(T);
    char **p;
    p=array(T);
    printf("Please input the array values (Note that '0' will be changed to '8' in case the position is correct):\n");
    array_input(T,p);
    printf("Here is what it looks like:\n");
    array_output(T,p);
    printf("Now please input the initial positon to apply the flood fill algorithm:\n");
    S=get_position();
    flood_fill(p,S,T,'0','8');
    printf("Here is the result:\n");
    array_output(T,p);
    printf("\n");
    free_array(T,p);

    return 0;
}
