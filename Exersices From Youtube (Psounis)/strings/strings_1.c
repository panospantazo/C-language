#include <stdio.h>
#include <stdlib.h>

int mystrlen(char *);

int main(void)
{
  char lexi[20],lexi2[20];
  printf("Dwste tin lexi\n");
  fgets(lexi,20,stdin);
  scanf("%s",lexi2);
  for(int i=0;lexi2[i]!='\0';i++)
   {
     printf("%d,%c",i,lexi2[i]);
   }
  printf("\n%s",lexi);
  printf("\nTo mhkos tis simvoloseiras einai %d\n",mystrlen(lexi));
  return 0;
}


int mystrlen(char *lexi)
{
  int i;
  for(i=0;lexi[i]!='\0';i++)
   {
    printf("%d,%c",i,lexi[i]);
   }
  return i;
}
