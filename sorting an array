#include<stdio.h>
int swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int a[10], b[10], c[20],i,j,k,d,e,f;
	printf("Enter total no. of elements for a[10]: ");
	scanf("%d", &d);
	printf("Enter the elements : ");
	for(i=1; i<=d; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for(i=1; i<=d; i++)
	{
		for(j=i+1; j<=d; j++)
		{
			if(a[i]<a[j])
			{
				swap(&a[i], &a[j]);
			}
		}
	}
	
	printf("Enter total no. of elements for b[10]: ");
	scanf("%d", &e);
	printf("Enter the elements : ");
	for(i=1; i<=e; i++)
	{
		scanf("%d", &b[i]);
	}
	
	for(i=1; i<=e; i++)
	{
		for(j=i+1; j<=e; j++)
		{
			if(b[i]<b[j])
			{
				swap(&b[i], &b[j]);
			}
		}
	}
	
	printf("The sorted first array : ");
	for(i=1; i<=d; i++)
	{
		printf("%d ", a[i]);
	}
	
	printf("\nThe sorted second array : ");
    for(i=1; i<=e; i++)
	{
		printf("%d ", b[i]);
	}
	
}
