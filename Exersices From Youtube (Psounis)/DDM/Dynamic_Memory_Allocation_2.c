#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
int main(void)
{
 //STATIKOS PINAKAS

  int n;
  srand(time(NULL));
  do{
    printf("Dwse tis diastaseis toy pinaka(5-20)\n");
    scanf("%d",&n);
    if(n<5 || n>20)
     printf("Lathos eisodos\n");
  }while(n<5 || n>20);
  printf("\n");
  int a[n][n];
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<=i;j++)
   {
     a[i][j] = 1+rand()&9;
   }

  for(int j=i+1;j<n;j++)
    {
      a[i][j] = 0;
    }
   }
  printf("O STATIKOS PINAKAS\n");
  printf("--------------------\n");
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<n;j++)
   {
     printf("%d ",a[i][j]);
   }
   printf("\n");
  }

//---------------------------------------------------------

 //DYNAMIKOS PINAKAS

  int **b;
  b = (int **)malloc(n * sizeof(int *));
  if(!b)
  {
   printf("Adynamia desmeusis mnimis!");
   exit(0);
  }
  for(int i=0;i<n;i++)
  {
      b[i] = (int *)malloc((i+1) * sizeof(int));
      if(!b[i])
      {
        printf("Adynamia desmeusis mnimis!");
        exit(0);
      }
  }
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<=i;j++)
   {
     b[i][j] = 1+rand()&9;
   }
  }
  printf("O DYNAMIKOS PINAKAS\n");
  printf("--------------------\n");
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<=i;j++)
     printf("%d ",b[i][j]);

   for(int j=i+1;j<n;j++)
     printf("0 ");

   printf("\n");
 }

//ANTIGRAFI A STON B

 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
  {
    b[i][j] = a[i][j];
  }
 }
 printf("ANTIGRAMENOS DYNAMIKOS PINAKAS\n");
 printf("------------------------------\n");
 for(int i=0;i<n;i++)
  {
   for(int j=0;j<=i;j++)
   {
     printf("%d ",b[i][j]);
   }
   for(int j=i+1;j<n;j++)
   {
     printf("0 ");
   }
   printf("\n");
  }
  for(int i=0;i<n;i++)
   {
    free(b[i]);
   }
   free(b);
 return 0;
}
