#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
int partition (int a[],int low,int high)
{
	int t;
	int pivot = a[high];
	int i=low-1;
	for(int j=low;j<=high;j++)
	{
		if (a[j]<pivot)
		{
			i++;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	t = a[i+1];  
	a[i+1] = a[high];  
	a[high] = t;  
	return (i + 1); 
}
void quick(int a[],int low,int high)
{
	if (low < high)
	{
		int p=partition(a,low,high);
		quick(a,low,p-1);
		quick(a,p+1,high);
	}
}
void printArr(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
} 
int main()
{

	struct timeval t0;
	struct timeval t1;
	float elapsed;
	
	srand( (unsigned) time(NULL) * getpid());   
	
	int i, n;
     	int a[100];
	printf("Enter the number of elements:");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		a[i]=rand()%100;
	}
	printf("The elements are:\n");
	for(i=0;i<n;i++)
       {
            printf("%d \t",a[i]);
       }
       printf("\n");
	
	 gettimeofday(&t0, NULL);	
        quick(a,0,n-1);
        gettimeofday(&t1, NULL);
        
       printf("Order of Sorted elements:\n ");
       for(i=0;i<n;i++)
       {
            printf("%d\t",a[i]);
       }
        printf("\n");
        
        elapsed = timedifference_msec(t0, t1);
   	printf("Code executed in %f milliseconds.\n", elapsed);
   	printf("\n");
       return 0;
}
