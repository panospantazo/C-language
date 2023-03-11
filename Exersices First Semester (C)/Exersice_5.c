#include <stdio.h>
int main(void)
{ int i;
  for(i=65;i<=90;i++)
    printf("%c\t%d\n",i,i);
  printf("----------------\n");
  for(i=97;i<=122;i++)
    printf("%c\t%d\n",i,i);
  return 0;
}

