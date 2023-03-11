#include <stdio.h>
int main(void)
{ int i=65;
  do
    printf("%c\t%d\n",i,i);
  while(++i<=90);
  printf("----------------\n");
  i=97;
  do
    printf("%c\t%d\n",i,i);
  while(++i<=122);
  return 0;
}
