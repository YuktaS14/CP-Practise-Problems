#include <stdio.h>

int main()
{
	int n, k;
	scanf("%d", &n);
	
	int A[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	
	scanf("%d", &k);	
	
	int pivot = A[k];
	//number of elements less than A[k]
	int r = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i] < A[k])
			r++;
	}
	
	int temp = A[k];
	A[k] = A[r];
	A[r] = temp;
	
	
	int i = 0, j = (r + 1);
	while((i < r) && (j < n))
	{
		while((i < r) && (A[i] < A[r]))
			i++ ;
		while((j < n) && (A[j] >= A[r]))
			j++ ;
		if((i < r) && (j < n))
		{
			int temp1 = A[i];
			A[i] = A[j];
			A[j] = temp1;
			i++;
			j++;
		}
	}
    	
	for(int i = 0; i < n; i++)
	{
		printf("%d\n", A[i]);
	}
	return 0;
}