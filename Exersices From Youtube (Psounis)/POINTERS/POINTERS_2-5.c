#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000


void init_array(int *pinakas,int n,int a,int b);
void print_array(int *pinakas,int n);
int max_array(int *pin,int n);


main()
{
  int ch,n,array[SIZE],a,b;	
  do
  {
  	printf("MENOY EPILOGWN\n");
  	printf("-----------------------\n");
    printf("1.Epelexe poses theseis thes na desmeuseis.\n");
    printf("2.Gemise ton me tyxaious arithmous.\n");
    printf("3.Vres ton megisto arithmo tou pinaka.\n");
    printf("4.Typwse olous tous arithmous tou pinaka.\n");
    printf("5.Exit\n");
    printf("Epilogi: ");
    scanf("%d",&ch);
    if(ch == 1)
	{
	  printf("Desmeuw: ");
      scanf("%d",&n);
      printf("\n");
    }
    else if(ch == 2)
	{
      printf("Poies thes na einai ta oria twn tyxaiwn arithmwn: ");
      scanf("%d",&a);
      scanf("%d",&b);
	  init_array(array,n,a,b);
	  printf("Egine h arxikopoihsh toy pinaka!\n");
    }
	else if(ch == 3)
	  printf("\nMAX=%d\n",max_array(array,b=n));
	else if(ch == 4)
	   print_array(array,n);
	else
	   break;
	}while(1); 
  printf("Bye Bye!");     
}


void init_array(int *pinakas,int n,int a,int b)
{
  int i;
  srand(time(NULL));
  for(i=0;i<n;i++)
    pinakas[i] = a+rand()%(b-a+1);
}
 
void print_array(int *pinakas,int n)
{
  int i;
  printf("[");	
  for(i=0;i<n-1;i++)
    printf("%d,",pinakas[i]);
  printf("%d]\n",pinakas[n-1]);
}


int max_array(int *pin,int n)
{
  int i,max = pin[0];
  for(i=1;i<n;i++)
  {
    if(max < pin[i])
      max = pin[i];
  }	
  return max;
}
