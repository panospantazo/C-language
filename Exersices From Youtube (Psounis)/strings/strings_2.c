#include <stdio.h>

char mystrcpy(char *,char *);

int main(void)
{
  int choice;
  char a[15],b[15],c[15];
  printf("Dwse moy thn prwth simvoloseira: ");
  gets(a);
  printf("Dwse moy thn deuterh simvoloseira: ");
  gets(b);
  printf("%s\t%s",a,b);
  printf("\nEpelexe mia simvoloseira 1/2\n");
  scanf("%d",&choice);
  if(choice == 1)
    mystrcpy(c,a);
  else
    mystrcpy(c,b);
  printf("\n\n1: %s \n\n2: %s  \n\n3: %s\n",a,b,c);

}


char mystrcpy(char *dest,char *src)
{
  int i=0;
  while(src[i] != '\0')
  {
     dest[i] = src[i];
     i++;
  }
    dest[i] = '\0';
    return dest;
}
