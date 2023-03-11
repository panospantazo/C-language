#include <stdio.h>

int is_even(int n);
int is_odd(int n);
int is_square(int n);
int is_cube(int n);

main()
{
 int num,x,y,z,c;
 printf("Give me any number: ");
 scanf("%d",&num);
 
 if(is_even(num))
   printf("Einai artios!\n");
 
 if(is_odd(num))
   printf("Einai perritos!\n");
 
 if(is_square(num))
   printf("Einai tetrawno arithmoy!\n");
 
 if(is_cube(num))
   printf("Einai kivos arithmoy!");     
 

}

int is_even(int n)
{ 
  if(n%2==0)
   return 1;
  else
   return 0;   
}

int is_odd(int n)
{
  if(n%2 != 0)
    return 1;
  else
    return 0;  
}

int is_square(int n)
{
  int i=1;
  for(i=1;i<=n;i++)
  {
    if(i * i == n)
      return 1;
    else if(i*i>n)
	  return 0; 
  }
}


int is_cube(int n)
{
  int i=1;
  for(i=1;i<=n;i++)
  {
    if(i * i* i == n)
      return 1;
    else if(i*i*i>n)
	  return 0; 
  }
}





