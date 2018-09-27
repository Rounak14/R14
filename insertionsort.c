#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int *,int);
void print(int *,int);

int main()
{
	int n;
	printf("\nEnter the sizeof array : ");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the %d element : ",i+1);
		scanf("%d",&a[i]);
	}
	print(a,n);
	clock_t begin=clock();
	insertion(a,n);
	clock_t end=clock();
	double time_taken=(double)(end-begin)/CLOCKS_PER_SEC;
	print(a,n);
	printf("Time taken : %f",time_taken);
}

void insertion(int *a,int n)
{
	int temp;
	for(int i=1;i<n;i++)
	{
		for(int j=i;j>=0;j--)
		{
			if(a[j]>a[j-1])
			{
				break;
			}
			else
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
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