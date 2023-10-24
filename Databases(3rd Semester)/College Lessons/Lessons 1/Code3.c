/*Seeing how float numbers are stored binary inside the memory*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    float a = 1.1, b = 2.2 , c = 3.3 , d;

    if(a + b == c)
    {
        printf("a + b = c\n");
    }
    else
    {
        printf("a + b != c\n");
    }
    
    d = a+b;
    if(d == c)
    {
        printf("d = c\n");
    }
    else
    {
        printf("d != c\n");
    }

    printf("a = %.18f\nb=%.18f\nc=%.18f\nd=%.18f\n",a,b,c,d);

    if(fabs(d-c) < 0.0001)
    {
        printf("OK\n");
    }
    else
    {
        printf("Not OK\n");
    }

    return 0;
}