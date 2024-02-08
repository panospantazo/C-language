#include <stdio.h>
#include <stdlib.h>

float* MO(float **arr,int M,int N);

int main(int argv,char*argc[])
{
	int M,N,i,j;
	float **arr,*M_O;
	printf("Posous foitites thes: ");
	scanf("%d",&M);
	printf("Posa mathimata thes: ");
	scanf("%d",&N);
	
	arr = malloc(sizeof(float *) * M);
	if(!arr)
	{
		printf("Memory Problem\n");
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
			printf("Dwse gia ton %do foititi ton vathmo toy %dou mathimatos: ",i+1,j+1);
			scanf("%f",&arr[i][j]);
			printf("\n");
		}
	}
	
	M_O = MO(arr,M,N);
	
	for(i=0;i<N;i++)
	{
		printf("O mesos oros toy %dou mathimatos einai %f\n",i+1,M_O[i]);
	}
	
	free(M_O);
	for(i=0;i<N;i++)
	{
		free(arr[i]);
	}
	free(arr);
	return 0;
}

float* MO(float **arr,int M,int N)
{
	int i,j,sum;
	float *M_O;
	M_O = malloc(sizeof(float) * N);
	if(!M_O)
	{
		printf("Memory problem");
		exit(EXIT_FAILURE);
	}
	
	for(j=0;j<N;j++)
	{
		sum = 0;
		for(i=0;i<M;i++)
		{
				sum+=arr[i][j];
		}
		M_O[j] = sum/M;
	}
	
	return M_O;
}
