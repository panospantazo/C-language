#include <stdio.h>
int main(void)
{
  int i,k;
  char a[150];
  printf("Dwse thn simvoloseira:\n");
  gets(a);
  i=0;
  while(a[i] != '\0')
  {
    if(a[i]>=97 && a[i]<=122)
     {
       a[i] = a[i] -32; 
     }
   i++;
}
  printf("%s\n",a);
}
