#include <stdio.h>
int main(void)
{ int i=64;
  while(++i<=90)
    printf("%c\t%d\n",i,i);
  printf("----------------\n");
  i=96;
  while(++i<=122)
    printf("%c\t%d\n",i,i);
  return 0;
}
