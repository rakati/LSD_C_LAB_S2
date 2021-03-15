#include "header.h"

int recursive_fibo(int n)
{
    if(n<=1)
        return n;
    return rec_fib(n-1)+rec_fib(n-2);
}
