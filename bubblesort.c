#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(int *,int);
void print(int *,int);


int main()
{
	int Size;
	printf("\nEnter the size of array : ");
	scanf("%d",&Size);
	int a[Size];
	for(int i=0;i<Size;i++)
	{
		printf("\nEnter the %dth element : ",i+1);
		scanf("%d",&a[i]);
	}
	print(a,Size);
	printf("\nBubble sorted : ");
	clock_t begin=clock();
	bubble(a,Size);
	clock_t end=clock();
	double time_taken=(double)(end-begin)/CLOCKS_PER_SEC;
	print(a,Size);
	printf("Time taken : %f",time_taken);
}

void print(int *a,int Size)
{
	printf("[ ");
	for(int i=0;i<Size;i++)
	{
		printf("%d ",a[i]);
	}
	printf("]\n");
}
void bubble(int *a,int Size)
{
	int n=Size;
	while(n>0)
	{
		for(int i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				int temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
		n--;
	}
}
