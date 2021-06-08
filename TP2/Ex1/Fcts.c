#include "header.h"



void input(t_point * T){
    scanf("%d %d",&T->base,&T->height);
    return ;
}

void output(t_point T){
    printf("( %d , %d )\n",T.base,T.height);
    return ;
}

char** array(t_point T)
{
    char** arr = malloc(T.base*sizeof(char*));
    for (int i=0; i<T.base; i++)
    {
        arr[i] = malloc(T.height* sizeof(char)) ;
    }
    return arr;
}

char** array_input(t_point T,char ** p){
    for (int i = 0; i < T.base; i++)
    {
        for (int j = 0; j < T.height; j++)
        {
            scanf(" %c",&p[i][j]);
        }
        
    }
    return p;
}

void array_output(t_point T,char** p){
	for (int i = 0; i < T.base; i++)
	{
        	for (int j = 0; j < T.height; j++)
        	{
            		printf("%c ",p[i][j]);
        	}
        	printf("\n");
        
	}
}

t_point get_position(){
    t_point T;
    input(&T);
    return T;
}


void flood_fill(char** p,t_point T,t_point D,char c, char d){
    if(T.base<0 || T.base>=D.base || T.height<0 || T.height>=D.height)
        return;
    if(p[T.base][T.height]==c){
        p[T.base][T.height]=d;
        flood_fill(p , (t_point){T.base+1,T.height} , D, c , d);
        flood_fill(p , (t_point){T.base-1,T.height} , D, c , d);
        flood_fill(p , (t_point){T.base,T.height+1} , D, c , d);
        flood_fill(p , (t_point){T.base,T.height-1} , D, c , d);
        
    }
}





void free_array(t_point T,char** arr)
{
    for (int i=0; i<T.base; i++)
    {
        free(arr[i]);
    };
    free(arr);
    return ;
}
