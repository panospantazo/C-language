#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

void mini(int arr[],int **ptr,int **ptr1);

int main(int argv,char * argc[])
{
	printf("%d\n",'z');
	
	srand(time(NULL));
	int i,min,min1;
	int *arr,*ptr,*ptr1;
	
	arr = malloc(sizeof(int) *SIZE);
	if(!arr)
	{
		printf("Memory Problem!\n");
		exit(EXIT_FAILURE);
	}
	
	for(i=0;i<SIZE;i++)
	{
		arr[i] = 1+rand()%50;
	}
	
	for(i=0;i<SIZE;i++)
	{
		printf("%d)%d\n",i+1,arr[i]);
	}
	
	min=arr[0];
	min1=arr[1];
	
	ptr = &min;
	ptr1=&min1;
	
	mini(arr,&ptr,&ptr1);
	printf("MIN 1: %d\nMIN 2: %d",min,min1);
	
	
	free(arr);
	return 0;
}

void mini(int arr[],int **ptr,int **ptr1)
{
	int i;
	for(i=1;i<SIZE;i++)
	{
		if(**ptr > arr[i])
		{
			if(**ptr1 > arr[i] && **ptr1 != **ptr)
			{
				**ptr1 = arr[i];
			}
			else
			{
				**ptr = arr[i];
			}
		}
		else
		{
			if(**ptr1 > arr[i] && **ptr1 != **ptr)
			{
				**ptr1 = arr[i];
			}
		}
		
	}

}
