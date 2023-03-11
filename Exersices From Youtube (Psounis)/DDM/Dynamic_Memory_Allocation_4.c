#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

int check(char *);

int main(void)
{
  int i;
  char *words[SIZE],buff[5000];
  printf("\n\n");
  for(i=0;i<SIZE;i++)
  {
    printf("Dwse tin lexi poy epithimis me mikrous latinikous xaraktires: ");
    gets(buff);
    if(check(buff) == 0)
    {
      printf("Lathos eisodo\n");
      exit(0);
    }
    *(words + i) = malloc(sizeof(char) * (strlen(buff) + 1));
    if(!words[i])
    {
      printf("Adynamia desmeusis mnimis\n");
      exit(0);
    }
    strcpy(*(words + i),buff);
  }
  for(i=0;i<SIZE;i++)
     printf("Symvoloseira %d)%s\n",i,*(words + i));

  for(i=0;i<SIZE;i++)
  {
    free(words[i]);
  }
 return 0;
}


int check(char *buff)
{
  int i=0;
  while(*(buff+i)!='\0')
  {
    if(*(buff + i)>=97 && *(buff + i) <= 122)
    {
      i++;
    }
    else
    {
      return 0;
    }
   }
   return  1;
}
