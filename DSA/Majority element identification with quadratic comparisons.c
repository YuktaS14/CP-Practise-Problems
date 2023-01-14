#include <stdio.h>

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int A[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	
	int maxf = 0, f = 0, k = 0;
	for(int j = 0; j < n; j ++)
	{
		for(int i = 0; i < n; i++)
		{
			if(A[j] == A[i])
			{
				f++;
				maxf= max(maxf,f);
				if(maxf == f)
				{
					k = j;
				}
			}
		}
		f = 0;
	}
	
	if(maxf > (n/2))
	{
		printf("%d \n", A[k]);
	}
	else
	{
		printf("No Majority \n");
	}
	return 0;
}