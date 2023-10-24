/*Saving memory from the initialization placement of data. Also seeing how variables are stored in memory addresses*/
#include <stdio.h>
#include <stdlib.h>

struct test
{
    char first;
    char mid;
    char last;
    int b;
};

int main(void)
{
    struct test bla[] = { {'a',4,'b','c'} , {'a',4,'b','c'} };
    int n = sizeof(bla) / sizeof(struct test);
    printf("n = %d\n",n);
    printf("Size pf char = %d , int = %d , struct test = %d\n",sizeof(char),sizeof(int),sizeof(struct test));
    
    printf("bla[0].first is at:%d\n",&bla[0].first);
    printf("bla[0].mid is at:%d\n",&bla[0].mid);
    printf("bla[0].last is at:%d\n",&bla[0].last);
    printf("bla[0].b is at:%d\n",&bla[0].b);

    printf("bla[1].first is at:%d\n",&bla[1].first);
    printf("bla[1].mid is at:%d\n",&bla[1].mid);
    printf("bla[1].last is at:%d\n",&bla[1].last);
    printf("bla[1].b is at:%d\n",&bla[1].b);

    return 0;




}