#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int tsekarisma(char *);
int sigkrisi(char *,char *);

int main(void)
{
 int x;
 char a[SIZE],b[SIZE];
 printf("Pliktrologise tin prwti soy simvoloseira\n");
 gets(a);
 x=tsekarisma(a);
 if(x==0)
  {
   printf("\n1)As evazes mikro gramma\n");
   exit(0);
  }
  printf("Pliktrologise tin deuteri sou simvoloseira\n");
  gets(b);
  x=tsekarisma(b);
  if(x==0)
   {
    printf("\n2)As evazes mikro gramma\n");
    exit(0);
   }
   x = sigkrisi(a,b);
   if(x==0)
     printf("%s > %s\n",b,a);
   else
     printf("%s > %s\n",a,b);
  return 0;
}







int tsekarisma(char *a)
{
  int  cnt = 0;
  while(a[cnt] != '\0')
  {
    if(a[cnt]<97)
      return 0;
    else
      return 1;
    cnt++;
  }
}




int sigkrisi(char *a,char *b)
{
  int i=0;
  while(a[i] != '\0' || b[i] != '\0')
    {
      if(a[i] == b[i])
        i++;
      else if(a[i]>b[i])
        return 1;
      else
        return 0;
    }
    if(a[i] == '\0')
      return 0;
    if(b[i] == '\0')
      return 1;
}
