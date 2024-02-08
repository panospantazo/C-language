#include <stdio.h>
#include <stdlib.h>

float* M_O(float **arr,int N,int M);

int main(int argv,char*argc[])
{
	float **arr,*M_OS;
	int N,M,i,j;
	
	printf("Posoi einai oi foitites: ");
	scanf("%d",&M);
	
	printf("Posa mathimata exoun: ");
	scanf("%d",&N);
	
	arr = malloc(sizeof(float*) * M);
	if(!arr)
	{
		printf("Memory Problem!");
		exit(EXIT_FAILURE);
	}
	
	for(i=0;i<N;i++)
	{
		arr[i] = malloc(sizeof(float) * N);
		if(!arr[i])
		{
			printf("Memory Problem!");
			exit(EXIT_FAILURE);
		}
	}
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("Dwste vathmo gia to %do mathima toy %dou foititi: ",j+1,i+1);
			scanf("%f",&arr[i][j]);
			printf("\n");
		}
	}
	
	
	M_OS = M_O(arr,N,M);
	
	for(i=0;i<M;i++)
	{
		printf("O mesos oros toy %dou foititi einai %f\n",i+1,M_OS[i]);
	}
	
	for(i=0;i<N;i++)
	{
		free(arr[i]);
	}
	free(arr);
	free(M_OS);
	return 0;
}

float* M_O(float **arr,int N,int M)
{
	int i,j;
	float *M_U,sum;
	M_U = malloc(sizeof(float) * M);
	if(!M_U)
	{
		printf("Memory Problem");
		exit(EXIT_FAILURE);
	}
	
	for(i=0;i<M;i++)
	{
		M_U[i] = 0;
	}
	
	for(i=0;i<M;i++)
	{
		sum = 0;
		for(j=0;j<N;j++)
		{
			if(arr[i][j] >= 5)
			{
				sum+=arr[i][j];
			}
		}
		M_U[i] = (sum/N);
	}
	return M_U;
}
