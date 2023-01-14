#include <stdio.h>

long int max(long int a,long int b)
{
	if(a > b)
		return a;
	else
		return b;
}

void Sort(int n, long int arr[])
{
	if(n == 1)
		return;
	else
	{
		long int largest = arr[0];
		int k = 0;
		for(int i = 0; i < n; i++)
		{
			largest = max(largest, arr[i]);
			if(largest == arr[i])
			{
				k = i;		
			}
		}
		
		long int temp = arr[n-1];
		arr[n-1] = arr[k];
		arr[k] = temp;
	}
	
	Sort(n-1, arr);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	long int arr[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%ld", &arr[i]);	
	}
	
	Sort(n, arr);
	
	for(int i = 0; i < n; i++)
	{
		printf("%ld\n", arr[i]);
	}
	return 0;
}