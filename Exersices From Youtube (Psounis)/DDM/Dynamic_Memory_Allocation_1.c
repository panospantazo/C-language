#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int i,gramm,st;
  double **p;
  printf("Poses grammes xreiazesai?\n");
  scanf("%d",&gramm);
  printf("Poses sthles xreiazesai?\n");
  scanf("%d",&st);
  p = malloc(gramm * sizeof(double *));
  if(!p)
  {
    printf("Apotyxia desmeusis mnimis!\n");
    exit(0);
   }
  for(i=0;i<gramm;i++)
  {
   p[i] = malloc(st * sizeof(double));
   if(!p[i])
   {
     printf("Apotyxia desmeusis mnimis!\n");
     exit(0);
   }
  }
  printf("O xwros poy desmeutike dynamika einai %ld: \n",st * gramm * sizeof(double) + gramm * sizeof(double *) + sizeof(double **));
  for(i=0;i<gramm;i++)
    free(p[i]);
 free(p);
}

