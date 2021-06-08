#include "stack.h"

int add(int x, int y){
    return x+y;
}

int sub(int x, int y){
    return x-y;
}

int mul(int x, int y){
    return x*y;
}

int divd(int x, int y){
    if(y==0){
        printf("Division by zero.\n");
        exit(EXIT_FAILURE);
    }
    return x/y;
}

int mod(int x, int y){
    if(y==0){
        printf("Modulo Op by zero.\n");
        exit(EXIT_FAILURE);
    }
    return x%y;
}

char** form(char* s){
	char delim[] = " ";

    char str[strlen(s)];
    int j=0;

    for(int i=0;i<strlen(s);i++){
        str[i]=s[i];
    }
	char *ptr = strtok(str, delim);

	while(ptr != NULL)
	{
		ptr = strtok(NULL, delim);
        j++;
	}
    char** expr=(char**)malloc(j*sizeof(char*));

    char *ptr_2 = strtok(s, delim);

    int i=0;

    while(ptr_2 != NULL)
	{
        expr[i]=ptr_2;
		ptr_2 = strtok(NULL, delim);
        i++;
	}
    return expr;
}



int number(char* string){
    int s=0;
    for(int j=0;j<strlen(string);j++){
        s = s * 10 + (string[j] - '0');
    }
    return s;
}

void stack_error(t_stack* head){
    if(is_empty(head) || stack_len(head)==2){
            printf("Error.\n");
            exit(EXIT_FAILURE);
        }
}

int size(char* s){
    char delim[] = " ";

    char str[strlen(s)];
    int j=0;

    for(int i=0;i<strlen(s);i++){
        str[i]=s[i];
    }
	char *ptr = strtok(str, delim);

	while(ptr != NULL)
	{
		ptr = strtok(NULL, delim);
        j++;
	}
    return j;
}

void operation(t_stack** head, int n){
    int r;
    int (*ops[])(int,int)={add,sub,mul,divd,mod};
    stack_error(*head);
    r=(ops[n])(pop(head),pop(head));
    push(head,r);
    return;
}

void formula(char** n, int j){
    t_stack P={0,NULL};
    t_stack* head=&P;
    int r;
    int (*ops[])(int,int)={add,sub,mul,divd,mod};

    for(int i=0;i<j;i++){
        switch (n[i][0])
        {
        case '+':
            operation(&head,0);
            break;
        case '-':
            operation(&head,1);
            break;
        case '*':
            operation(&head,2);
            break;
        case '/':
            operation(&head,3);
            break;
        case '%':
            operation(&head,4);
            break;
        default:
            push(&head,number(n[i]));
            break;
        }
    }
    if(stack_len(head)==2){
        printf("The result is : %d\n",pop(&head));
    }
    else{
        printf("Error in formula.\n");
    }
    return;
}

int main(int ac, char** av){
    char* s=av[1];
    formula(form(s),size(s));
    free(form(s));
    return 0;
}