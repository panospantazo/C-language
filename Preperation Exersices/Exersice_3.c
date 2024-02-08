#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void search_max_min(int arr[],int **ptr,int **ptr1);

int main(int argv,char * argc[])
{
	int i,max=0,min;
	int *arr,*ptr,*ptr1;
	arr = malloc(sizeof(int)*SIZE);
	if(!arr)
	{
		printf("Memory Problem\n");
		exit(EXIT_FAILURE);
	}
	
	for(i=0;i<SIZE;i++)
	{
		arr[i] = i;
	}
	min = arr[0];
	
	ptr = &max;
	ptr1 = &min;
	
	search_max_min(arr,&ptr,&ptr1);
	
	printf("MAX: %d\n",max);
	printf("MIN: %d\n",min);
	
	free(arr);	
	return 0;
}

void search_max_min(int arr[],int **ptr,int **ptr1)
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		if(arr[i] > **ptr)
		{
			**ptr = arr[i];
		}
		
		if(arr[i] < **ptr1)
		{
			**ptr1 = arr[i];
		}
	}
}
