#include <stdio.h>
#include <stdlib.h>

double * Memory_Allocating_Array(double L,int N);

int main(int argv, char* argc[])
{
	double L,*arr;
	int N,i;
	
	printf("Dwste moy poses theseis thelete na desmeusw ston pinaka: ");
	scanf("%d",&N);
	
	printf("Dwste moy thn timh poy thelete na arxikopoihsw ton pinaka: ");
	scanf("%lf",&L);
	
	arr = Memory_Allocating_Array(L,N);

	for(i=0;i<N;i++)
	{
		printf("%lf\n",arr[i]);
	}
	
	free(arr);
	
	return 0;
}

double* Memory_Allocating_Array(double L,int N)
{
	int i;
	double *arr;
	arr = malloc(sizeof(double)*N);
	if(!arr)
	{
		printf("Memory Problem!\n");
		exit(EXIT_FAILURE);
	}
	for(i=0;i<N;i++)
	{
		arr[i] = L;
	}
	
	return arr;
}
