#include <stdio.h>

int isvowel(char x);

int main(void)
{ char x;
  int output;
  printf("Give me a character: ");
  x = getchar();
  output = isvowel(x);
  printf("%d",output);
  return 0;
}

 
int isvowel(char x)
{ int output;
  if(x=='a' || x=='o' || x=='e' || x=='i' || x=='u')
  {
    output = 1;
  }
  else
  {
    output = 0;
  }
  return output; 
}
